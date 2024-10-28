/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:09:51 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 13:10:00 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
// #include <stdio.h>
// int main()
// {
// 	int i = 0;
// 	char str[] = "hippo hippo";
// 	ft_bzero(str, 3);
// 	while (i < 12)
// 	{
// 		if (str[i] == 0)
// 		{
// 			printf(" there is 0 ");
// 		}
// 		else
// 			printf("%c", str[i]);
// 		i++;
// 	}
// }
