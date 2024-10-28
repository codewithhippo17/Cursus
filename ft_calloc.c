/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:11:53 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/28 17:33:35 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, nmemb * size);
	return (res);
}
