/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:37:07 by ehamza            #+#    #+#             */
/*   Updated: 2025/01/23 12:09:09 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		message = ft_strdup(argv[2]);
		pid = ft_atoi(argv[1]);
		while (message[i] != '\0')
		{
			ft_send_bits(pid, message[i]);
			i++;
		}
	}
	ft_send_bits(pid, message[i]);
	free(message);
	return (0);
}