/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:59:04 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/23 00:09:42 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# define BUFFER_SIZE 6

char	*read_buffer(int fd, char *s_buffer);
char	*reload(int fd, char *word, char *s_buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_memchr(char *str, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s);

#endif