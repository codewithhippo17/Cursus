/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:39:16 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 18:39:17 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str1[] = "code with hippo";
//     printf("%s\n", (char *)ft_memcpy(str1 + 2, str1, 3)); 
//     char str2[] = "code with hippo";
//     printf("%s\n", (char *)memcpy(str2 + 2, str2, 3)); 
//     return 0;
// }
