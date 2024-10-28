/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:37:05 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 18:37:06 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = 0;
	if (c == 0)
		return ((char *)(s + i));
	while (s[i])
	{
		if (s[i] == (char)c)
			tmp = (char *)s + i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (tmp);
}

// #include <stdio.h>
// 
// int main()
// {
// 	char str[] = "code with hippo";
// 	printf("%s\n", ft_strrchr(str, 'i'));
// }
