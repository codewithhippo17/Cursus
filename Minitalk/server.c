/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasoulai <zasoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:18:31 by zasoulai          #+#    #+#             */
/*   Updated: 2025/03/24 11:47:13 by zasoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum, siginfo_t *act, void *tmp)
{
	static int		byte;
	static char		c;
	static pid_t	pid;

	(void)tmp;
	if (pid != act->si_pid)
	{
		byte = 7;
		c = 0;
		pid = act->si_pid;
	}
	if (signum == SIGUSR2)
		c |= 1 << byte;
	byte--;
	if (byte == -1)
	{
		if (c == '\0')
			c = '\n';
		write(1, &c, 1);
		byte = 7;
		c = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = signal_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigemptyset(&act.sa_mask) == -1)
		return (1);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		return (1);
	ft_putstr("The server PID : ", 1);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
