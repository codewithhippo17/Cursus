/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:17:04 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/13 00:42:21 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_read_file(int fd, t_map *s_map)
{
    char	*result;
    char	*current;
    char	*temp;

    result = get_next_line(fd);
    if (!result)
        return (s_map);
    while ((current = get_next_line(fd)) != NULL)
    {
        temp = result;
        result = ft_strjoin(result, current);
		if (!result)
			return (free(temp), free(current), s_map);
        free(temp);
        free(current);
    }
    s_map->line = ft_split(result, '\n');
    free(result);
    if (!s_map->line)
        return (s_map);
    return (s_map->valid = 1, s_map);
}

t_map	*calc_shape(t_map *s_map)
{
	char	**split;
	int 	checker;

	s_map->height = 0;
	checker = 0;
	while (s_map->line[s_map->height] != NULL)
	{
		split = ft_split(s_map->line[s_map->height], ' ');
		if (!split)
			return (s_map->valid = 0, s_map);
		if (checker == 0)
		{
			while (split[checker])
				checker++;
		}
		s_map->width = 0;
		while(split[s_map->width])
			s_map->width++;
		if (checker != s_map->width)
			return (ft_free_array(split), s_map->valid = 0, s_map);
		s_map->height++;
		ft_free_array(split);
	}
	s_map->valid = 2;
	return (s_map);
}


t_map	*v_cordz(t_map *s_map)
{
	char **split;
	int i;
	int j;

	i = 0;
	j = 0;
	while (s_map->line[i])
	{
		split = ft_split(s_map->line[i], ' ');
		if (!split)
			return (s_map->valid = 0, s_map);
		j = 0;
		while (split[j])
		{
			if (!(v_point(split[j])))
				return (s_map->valid = 0, ft_free_array(split), s_map);
			j++;
		}
		ft_free_array(split);
		i++;
	}
	return (s_map->valid = 3, s_map);
}


t_map	*read_map(t_map *s_map, int height, int width)
{
    char	**points;
    int		x;
    int		y;

    y = 0;
    s_map->point = (t_point **)malloc(sizeof(t_point *) * height);
    if (!s_map->point)
        return (s_map->valid = 0, s_map);
    while (y < height)
    {
        s_map->point[y] = (t_point *)malloc(sizeof(t_point) * width);
        if (!s_map->point[y])
            return (ft_free_point(s_map), s_map->valid = 0, s_map);
        points = ft_split(s_map->line[y], ' ');
        x = 0;
        while (x < width)
        {
            s_map->point[y][x] = read_point(points[x], x, y);
            x++;
        }
        ft_free_array(points);
        y++;
    }
    return (s_map->valid = 5, s_map);
}


t_map	*ft_parssing(int fd, t_map *s_map)
{
	s_map->valid = 0;
	s_map = ft_read_file(fd, s_map);
	if (s_map->valid == 1)
	{
		s_map = calc_shape(s_map);
		if (s_map->valid == 2)
		{
			s_map = v_cordz(s_map);
			if (s_map->valid == 3)
			{
				s_map = read_map(s_map, s_map->height, s_map->width);
				if (s_map->valid == 5)
					return (s_map);
			}
		}	
	}
	if (s_map->valid >= 1 && s_map->valid <= 3)
		ft_free_array(s_map->line);
	if (s_map->valid == 4)
	{
		ft_free_array(s_map->line);
		ft_free_point(s_map);
	}
	return (s_map);
}

// int main(int ac, char *av[])
// {
// 	if (ac == 2)
// 	{
// 		char *path;
// 		path = ft_strjoin("/home/codewithhippo/cursus/fdf/maps/", av[1]);
// 		if (!path)
// 			return (0);
// 		int fd = open(path, O_RDONLY);
// 		if (fd == -1)
// 		{
// 			printf("Error\n");
// 			return (1);
// 		}
// 		t_map *map;
// 		map = (t_map *)malloc(sizeof(t_map));
// 		if (!map)
// 			return (1);
// 		map->valid = 0;
//         map->height = 0;
//         map->width = 0;
//         map->line = NULL;
//         map->point = NULL;
// 		map = ft_parssing(fd, map);
// 		printf("%d\n", map->valid);
// 		close(fd);
// 		free(path);
// 		ft_free_map(map);
		// if (map->valid >= 1 && map->valid <= 3)
		// 	ft_free_array(map->line);
		// if (map->valid >= 4)
		// {
		// 	ft_free_map(map);
		// }
		

		// int i = 0;
		// while (map->line[i])
		// {
		// 	printf("%s\n", map->line[i]);
		// 	i++;
		// }
		// if (map->valid == 5)
		// 	printf("height: %d  width: %d\n", map->height, map->width);
		// else
		// {
		// 	printf("wa ta ser tqawed\n\n");
		// 	return (0);
		// }
		// int j;
		// i = 0;
		// j = 0;
		// while (i < map->height)
		// {
		// 	j = 0;
		// 	while (j < map->width)
		// 	{
		// 		printf("x: %d, y: %d, z: %d, color: %x\n", map->point[i][j].x, map->point[i][j].y, map->point[i][j].z, map->point[i][j].color);
		// 		j++;
		// 	}
		// 	i++;
		// }
// 	}
// 	return (0);
// }
