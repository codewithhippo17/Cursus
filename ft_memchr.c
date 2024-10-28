/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:20:45 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 14:20:48 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <unistd.h>
// int main()
// {
//     char str[] = "hipp sha oshippo";
//     char *res;
//     res = (char *)ft_memchr(str, 's',5);
//     int i = 0;
//     if (res == 0)
//     {
//         printf("not found\n");
//         return 0;
//     }
//     while (res[i])
//     {
//         write(1, &res[i], 1);
//         i++;
//     }
//     write(1, "\n", 1);
//     return 0;
// }
