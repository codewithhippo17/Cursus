/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:17:51 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 14:17:54 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[j])
	{
		join[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = 0;
	return (join);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc (ft_len(n) + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (str = "-2147483648");
	if (n < 0)
	{
		str = ft_itoa(-n);
		return (ft_strjoin("-", str));
	}
	if (n >= 0 && n <= 9)
	{
		str[0] = n + 48;
		str[1] = 0;
		return (str);
	}
	str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_itoa(19842));
// }
