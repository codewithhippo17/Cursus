/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:27:03 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/13 00:51:47 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_strlenz(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ',')
	{
		i++;
	}
	return (i);
}

void ft_free_point(t_map s_map)
{
	int i;

	i = 0;
	while (s_map.point[i])
	{
		free(s_map.point[i]);
		i++;
	}
	free(s_map.point);
}

void ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_point    read_point(char *point, int x, int y)
{
	t_point	s_point;

	if (!point)
		return (t_point){0, 0, 0, 0xFFFFFF};
	s_point.x = x;
	s_point.y = y;
	s_point.z = ft_atoi(point);
	s_point.color = get_color(ft_strchr(point, ','));
	return (s_point);
}