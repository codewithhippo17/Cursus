/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:00:28 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/24 00:26:35 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[j])
	{
		join[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = 0;
	return (join);
}

char	*ft_memchr(char *str, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (str[i] == 10)
		
			return ((str + i));
		i++;
	}
	return (NULL);
}
char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
char	*ft_last(char *word)
{
	char	*last;
	int		i;

	i = 0;
	last = ft_strdup(word);
	if (!last)
		return (NULL);
	while (last[i] != 10 && last[i])
	{
		i++;
	}
	last[i + 1] = '\0';
	return (last);
}