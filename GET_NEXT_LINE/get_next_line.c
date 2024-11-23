/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:00:52 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/23 00:55:43 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_last(char *word)
{
	char	*last;
	int		i;

	i = 0;
	last = ft_strdup(word);
	if (!last)
		return (NULL);
	while (last[i] != 10)
	{
		i++;
	}
	last[i + 1] = '\0';
	return (last);
}

char	*reload(int fd, char *word, char *s_buffer)
{
	char	*line;
	// printf("%s", s_buffer);
	line = ft_strjoin(word, read_buffer(fd, s_buffer));
	if (!line)
		return (NULL);
		// printf("%s", s_buffer);
	return (line);
}

char	*read_buffer(int fd, char *s_buffer)
{
	char	*word;
	int		size;

	if (s_buffer)
	{
		printf("hjksmv,l;.ds");
		return (reload(fd, s_buffer, s_buffer));
	}
	word = malloc(BUFFER_SIZE + 1);
	if (!word)
		return (NULL);
	size = read(fd, word, BUFFER_SIZE);
	if (size == -1 || size == 0)
		return (NULL);
	s_buffer  = ft_memchr(word, size);
	if (!s_buffer)
		return (word[size] = '\0', reload(fd, word, s_buffer));
	s_buffer++;
	return (ft_last(word));
}

char	*get_next_line(int fd)
{
	static char *s_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_buffer(fd, s_buffer);
	// printf("%s", s_buffer);
	return (line);
}

int main()
{
	int fd = open("ttt", O_RDWR, 0777);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
}
