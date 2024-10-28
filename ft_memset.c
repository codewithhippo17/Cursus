/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:25:15 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 14:25:18 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
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

// #include <stdio.h>
// int main()
// {
// 	char str[] = "dbvuhn dvudsvsv ";
// 	printf("%s\n", (char *)ft_memset(str, 65, 5));
// }
