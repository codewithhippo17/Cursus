/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:24:39 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 14:24:41 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (src >= dest)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	printf("\n"); 	
// 	printf("\nft_memmove\n");
// 	char str1[] = "code with hippo";                              
// 	char *dest = (char *)ft_memmove(str1, str1 + 2, 6);
// 	puts(dest);
// 	printf("\nmemmove\n");
// 	char str2[] = "code with hippo";
// 	char *dest2 = (char *)memmove(str2, str2 + 2, 6);
// 	puts(dest2);
// 	return 0;
// }
