/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:20:12 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/15 21:17:42 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_isset(char c);
// int		ft_strlen(char *str);

////  ouput function  \\\\\.

int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_puthex(intptr_t n, char *base);

////  v_out funtions   \\\\\.

int		out_c(va_list args);
int		out_s(va_list args);
int		out_d(va_list args);
int		out_i(va_list args);
int		out_x(va_list args);
int		out_upx(va_list args);
int		out_p(va_list args);
int		out_u(va_list args);

#endif