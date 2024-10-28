/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:37:05 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 14:37:07 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d\n", ft_strncmp("hippo", "hippo", 5));
// 	printf("%d\n", ft_strncmp("hippa", "hippn", 5));
// 	printf("%d\n", ft_strncmp("hipp", "hippo", 5));
// 	printf("%d\n", ft_strncmp("hippoa", "hippo", 5));
// }
