#include "fdf.h"

int handle_keypress(int keycode, t_fdf *env)
{
    if (keycode == 65307)
    {
        mlx_loop_end(env->mlx);
        return (1);
    }
    return (0);
}

int handle_window_close(t_fdf *env)
{
    mlx_loop_end(env->mlx);
    return (0);
}

void ret_error(const char *msg, t_fdf *env, int exit_code)
{
    ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd("\n", 2);
    cleanup_and_exit(env);
    exit(exit_code);
}