/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:00:52 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/24 01:13:01 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	ft_save_buffer(char **reminder, char *buffer)
{
	// char	*buffer;
	size_t	len;
	size_t	i;

	i = 0;
	if (buffer)
	{
		// buffer++;
		len = ft_strlen(buffer);
		*reminder = malloc(len + 1);
		if (len != 0)
		{
			while (buffer[i])
			{
				reminder[0][i] = buffer[i];
				i++;
			}
			reminder[i] = '\0';
		}
	}
}

char	*reload(int fd, char *word)
{
	char	*line;

	line = ft_strjoin(word, read_buffer(fd));
	if (!line)
		return (NULL);
	return (line);
}

char	*read_buffer(int fd)
{
	static char *reminder;
	char		*word;
	char		*buffer;
	int			size;

	if (reminder)
	{
		word = ft_strdup(reminder);
		free(reminder);
		reminder = NULL;
		buffer = NULL;
	}
	else
	{
		word = malloc(BUFFER_SIZE + 1);
		if (!word)
			return (NULL);
		size = read(fd, word, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		buffer = ft_memchr(word, size);
		if (size == 0)
			return (ft_strdup(""));
	}
	if (buffer)
		return (word[size] = '\0', ft_save_buffer(&reminder, buffer + 1), ft_last(word));
	return (word[size] = '\0', reload(fd, word));
}

char	*get_next_line(int fd)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_buffer(fd);
	if (line[0] == 0)
		return (NULL);
	return (line);
}

int main()
{
	int fd = open("ttt", O_RDWR, 0777);
	char *line;
	while (line = get_next_line(fd))
	{
		printf("%s", line);
	}
	printf("%s", line);
}
