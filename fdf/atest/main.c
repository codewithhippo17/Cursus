// #include "/usr/include/minilibx-linux/mlx.h"
// #include <stddef.h>
// #include <stdlib.h>
// #include <stdio.h>

// #include "../includes/libft/libft.h"
// #include <stdio.h>
// #

// t_map	read_map(t_map s_map, int height, int width)
// {
// 	char	**points;
// 	int		x;
// 	int		y;

// 	y = 0;
// 	s_map.point = (t_point **)malloc(sizeof(t_point *) * height);
// 	if (!s_map.point)
// 		return (s_map.valid = 0, s_map);
// 	while (s_map.line[y] != NULL)
// 	{
// 		x = -1;
// 		points = ft_split(s_map.line[y], ' ');
// 		if (points == NULL)
// 			return (s_map.valid = 0, s_map);
// 		s_map.point[y] = (t_point *)malloc(sizeof(t_point) * width);
// 		if (s_map.point[y] == NULL)
// 			return (s_map.valid = 0, s_map);
// 		while (points[++x] != NULL)
// 			s_map.point[y][x] = read_point(points[x], x, y);
// 		free(points);
// 		y++;
// 	}
// 	return (s_map.valid = 1, s_map);
// }
// int	ft_atoi_base(char *point)
// {
// 	int	i;
// 	int	res;
// 	int	sign;

// 	i = 2;
// 	res = 0;
// 	while (point[i])
// 	{
//         if ((point[i] >= '0' && point[i] <= '9'))
//         {
// 		    res = res * 16 + point[i] - 48;
//         }
//         else if(point[i] >= 'a' && point[i] <= 'f')
//         {
//             res = res * 16 + point[i] - 87;
//         }
//         else if(point[i] >= 'A' && point[i] <= 'F')
//         {
//             res = res * 16 + point[i] - 55;
//         }
// 		i++;
// 	}
// 	return (res);
// }

// int main()
// {
//     printf("%s\n", ft_strchr("VDVBDV , VOUF3HVFV,", '3'));
// }





// // typedef struct	s_data {
// // 	void	*img;
// // 	char	*addr;
// // 	int		bits_per_pixel;
// // 	int		line_length;
// // 	int		endian;
// // }				t_data;



// // int main()
// // {
// //     void *mlx = mlx_init();
// //     void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Line");

// //     draw_line(mlx, win, 640, 360, 0, 0, 0xFFFFFF);

// //     mlx_loop(mlx);
// // }
// // #include <mlx.h>
// // #include <math.h>
// // #include <stdlib.h>

// // Function to draw a line between two points
// void draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
// {
//     int deltaX = abs(endX - beginX);
//     int deltaY = abs(endY - beginY);
//     int signX = beginX < endX ? 1 : -1;
//     int signY = beginY < endY ? 1 : -1;
//     int error = deltaX - deltaY;
//     int error2;

//     while (beginX != endX || beginY != endY)
//     {
//         mlx_pixel_put(mlx, win, beginX, beginY, color);
//         error2 = error * 2;
//         if (error2 > -deltaY)
//         {
//             error -= deltaY;
//             beginX += signX;
//         }
//         if (error2 < deltaX)
//         {
//             error += deltaX;
//             beginY += signY;
//         }
//     }
//     mlx_pixel_put(mlx, win, beginX, beginY, color);
// }

// int main()
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 1024, 1024, "Tutorial Window - Draw Line");

//     // Draw a white line from (10, 10) to (630, 350)
//     draw_line(mlx, win, 0, 0, 630, 350, 0xFFFFFF);

//     // Keep the window open
//     mlx_loop(mlx);

//     return 0;
// }