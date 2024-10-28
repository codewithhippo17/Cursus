/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:45:53 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/26 16:45:55 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[] = "co de wi th hip po";
// 	char dest[50];
// 	printf("%ld\n", ft_strlcpy(dest, str, 13));
// 	printf("%s\n", dest);

// 	char str1[] = "co de wi th hip po";
// 	char dest1[50];
// 	printf("%ld\n", ft_strlcpy(dest1, str1, 13));
// 	printf("%s\n", dest1);
// }
