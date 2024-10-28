/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:36:32 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 14:36:34 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

// char f(unsigned int i, char c)
// {
// 	char s;
// 	s = c;
// 	if(i % 2 == 0)
// 	{
// 		s = c - 32;
// 	}
// 	return (s);
// }
// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_strmapi("hippo", f));
// }
