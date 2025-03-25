/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasoulai <zasoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:42:15 by zasoulai          #+#    #+#             */
/*   Updated: 2025/03/22 10:26:45 by zasoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar((x % 10) + '0');
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;

	res = 0;
	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			res = (res * 10) + str[i] - 48;
		if (res > 2147483647 || !(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (res);
}
