#include "fdf.h"


// t_map   *ft_init_map(t_map *s_map)
// {
//     s_map = (t_map *)malloc(sizeof(t_map));
//     if (s_map == NULL)
//     {
//         ret_error("malloc error", 1);
//     }
//     s_map->height = 0;
//     s_map->width = 0;
//     s_map->valid = 0;
//     s_map->point = NULL;
//     s_map->line = NULL;
//     return (s_map);
// }

t_fdf	*ft_init(const char *path)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ret_error("malloc error", env, 1);
	env->title = ft_strjoin("FdF  ", path);
	env->mlx = mlx_init();
    ft_get_display(env);
	if (!env->mlx)
		ret_error("error connecting to graphics server", env, 1);
	env->win = mlx_new_window(env->mlx, env->screen_width, env->screen_height, env->title);
	if (!env->win)
		ret_error("error initializing window", env, 1);
    free(env->title);
	env->img = mlx_new_image(env->mlx, env->screen_width, env->screen_height);
	if (!env->img)
		ret_error("error initializing image",env, 1);
    env->s_map = (t_map *)malloc(sizeof(t_map));
    if (env->s_map == NULL)
    {
        ret_error("malloc error", env, 1);
    }
    // env->s_map = ft_init_map(env->s_map);
	return (env);
}




int main(int ac, char *av[])
{
    t_fdf *env;
    int fd;

    if (ac != 2)
        ret_error("Usage: ./fdf <filename>", NULL, 0);
    env = ft_init(av[1]);
    if (!env)
        ret_error("Failed to initialize", env, 1);
    fd = ft_file_format(env, av[1]);
    if (ft_parssing(fd, env->s_map)->valid != 5)
        ret_error("Parsing error", env, 1);
    mlx_hook(env->win, 2, 1L << 0, handle_keypress, env);
    mlx_hook(env->win, 17, 1L << 17, handle_window_close, env);
    mlx_loop(env->mlx);
    close(fd);
    cleanup_and_exit(env);
    return (0);
}