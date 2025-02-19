/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:39:42 by ehamza            #+#    #+#             */
/*   Updated: 2025/01/23 12:08:47 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_message = NULL;

char	*ft_joinc2str(char *s1, char c)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = ft_strdup("");
		return (ft_joinc2str(s1, c));
	}
	join = malloc(ft_strlen(s1) + 2);
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	while (s1[j])
		join[i++] = s1[j++];
	join[i++] = c;
	join[i] = '\0';
	free(s1);
	return (join);
}

void	sigusr1_handler(int sig)
{
	static int	nb = 0;
	static int	bit = 0;

	if (sig == SIGUSR1)
		nb |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (nb == '\0')
		{
			ft_printf("%s\n", g_message);
			free(g_message);
			g_message = NULL;
		}
		else
			g_message = ft_joinc2str(g_message, (char)nb);
		bit = 0;
		nb = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr1_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
