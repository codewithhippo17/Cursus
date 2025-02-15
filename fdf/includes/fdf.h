#ifndef FDF_H
# define FDF_H

#include <stdlib.h>


# include "/usr/include/minilibx-linux/mlx.h"
# include "../includes/gnl/get_next_line.h"
# include "../includes/ft_printf/libftprintf.h"
# include "../includes/libft/libft.h"
# include <X11/Xlib.h>


# define CURRENT_D CURRENT_DIR


typedef struct point
{
	int x;
	int y;
	int z;
	int color;
}t_point;


typedef struct s_map
{
	int		height;
	int		width;
	int		valid;
	t_point	**point;
	char	**line;
}t_map;


typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	char		*title;
	int     screen_width;
    int     screen_height;
	t_map		*s_map;
}				t_fdf;


// // // fdf functions \\ \\ \\.

t_fdf	*ft_init(const char *path);


// parssing functions\\.

t_map	*ft_parssing(int fd, t_map *s_map);
t_map	*ft_read_file(int fd, t_map *s_map);
t_map	*calc_shape(t_map *s_map);
t_map	*read_map(t_map *s_map, int height, int width);


// memory leaks functions\\.

void	ft_free_array(char **array);
void	ft_free_point(t_map *s_map);
void	ft_free_map(t_map *s_map);
void	ft_free_env(t_fdf *env);
void	cleanup_and_exit(t_fdf *env);


// parssing	utils functions\\.

t_point	read_point(char *point, int x, int y);
int		v_point(char *big);
int		get_color(char *point);
int		is_dec(char *big, int idx);
int		is_hex(char *big);
int		ft_strlenz(char *str);


// fdf helpers functions\\.
int		v_filename(char *filename);
void	ft_get_display(t_fdf *env);
int		ft_file_format(t_fdf *env, char *filename);


// fdf utils functions\\.
int     handle_keypress(int keycode, t_fdf *env);
int		handle_window_close(t_fdf *env);
void	ret_error(const char *msg, t_fdf *env, int exit_code);

# endif