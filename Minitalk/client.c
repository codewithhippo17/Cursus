/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasoulai <zasoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:25:11 by zasoulai          #+#    #+#             */
/*   Updated: 2025/03/24 11:26:03 by zasoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_flag;

static void	send_byte(char c, pid_t pid)
{
	int	byte;
	int	bit;
	int	n;

	byte = 7;
	while (byte >= 0)
	{
		bit = c >> byte & 1;
		if (bit == 0)
			n = kill(pid, SIGUSR1);
		else
			n = kill(pid, SIGUSR2);
		if (n == -1)
		{
			ft_putstr("PID is invalid\n", 2);
			exit(1);
		}
		byte--;
		while (g_flag == 0)
			;
		g_flag = 0;
	}
}

static void	signal_handler(int signum)
{
	(void)signum;
	g_flag = 1;
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr("Usage: ./client <PID> <STRING>\n", 2);
		return (1);
	}
	g_flag = 0;
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
		return (1);
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid == -1 || pid == 0)
		return (1);
	while (av[2][i])
	{
		send_byte(av[2][i], pid);
		i++;
	}
	send_byte('\0', pid);
	return (0);
}
