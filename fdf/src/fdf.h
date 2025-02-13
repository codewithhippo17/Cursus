#ifndef FDF_H
# define FDF_H

# include "../includes/gnl/get_next_line.h"
# include "../includes/ft_printf/libftprintf.h"
# include "../includes/libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"

typedef struct point
{
	int x;
	int y;
	int z;
	int color;
}t_point;


typedef struct map
{
	int		height;
	int		width;
	int		valid;
	t_point	**point;
	char	**line;
}t_map;


t_point	read_point(char *point, int x, int y);
t_map	read_map(t_map s_map, int height, int width);
int		get_color(char *point);
t_point    read_point(char *point, int x, int y);


void ft_free_array(char **array);
void ft_free_point(t_map s_map);
int	is_dec(char *big, int idx);
int is_hex(char *big);
int v_point(char *big);
int ft_strlenz(char *str);


# endif