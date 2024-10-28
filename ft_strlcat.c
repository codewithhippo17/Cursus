/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:05:40 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/26 17:05:42 by ehamza           ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (d_len >= size)
		return (size + s_len);
	while (src[i] && (d_len + i) < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = 0;
	return (s_len + d_len);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char dest[30] = "code hippo";
// 	char src[20] = "hippo hippo hippo";
// 	printf("%ld\n", strlcat(dest, src, 15));
// 	printf("%s\n", dest);

// 	char dest1[20] = "code hippo";
// 	char src1[20] = "hippo hippo hippo";
// 	printf("%ld\n", ft_strlcat(dest1, src1, 15));
// 	printf("%s\n", dest1);
// }
