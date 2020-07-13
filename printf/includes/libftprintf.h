/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:36:48 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 22:35:01 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//TODO check includes
#include <stdarg.h>
#include <stdio.h>

#include "../libft/libft.h"

typedef struct	s_pattern
{
	int	flag;
	int	precision;
}				t_pattern;

typedef struct	s_printer_head
{
	void	*ink;
	int		(*tape_measure)(void *value);
	void	(*extruder)(void *value, int len);
}				t_printer_head;

int		ft_printf(const char *, ...);

void	print_hexadecimal(int nb, int len_to_print, int is_upper_case);
int		return_length_of_int(int nb);
int		wrapper_return_lenght_of_int(void *value);
int		wrapper_return_lenght_of_char(void *value);
void	wrapper_ft_putchar_fd(void *value, int len_to_print);

int		handler_c(t_list *patterns, va_list argptr);
int		handler_s(t_list *patterns, va_list argptr);
int		handler_p(t_list *patterns, va_list argptr);
int		handler_d_i(t_list *patterns, va_list argptr);
int		handler_u(t_list *patterns, va_list argptr);
int		handler_x(t_list *patterns, va_list argptr);
int		handler_X(t_list *patterns, va_list argptr);

int		printer(t_list *patterns, t_printer_head *printer_head);
#endif