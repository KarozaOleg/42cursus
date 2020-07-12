/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:36:48 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/12 22:03:19 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//TODO check includes
#include <stdarg.h>
#include <stdio.h>

#include "../libft/libft.h"

int		ft_printf(const char *, ...);

int		return_length_of_int(int nb);
int		wrapper_return_lenght_of_int(void *value);

void	handler_c(char flag, int precision, va_list argptr);
void	handler_s(char flag, int precision, va_list argptr);
void	handler_p(char flag, int precision, va_list argptr);
void	handler_d_i(char flag, int precision, va_list argptr);
void	handler_u(char flag, int precision, va_list argptr);
void	handler_x(char flag, int precision, char conversation, va_list argptr);

void	printer(int flag, int precision, void *value, int (*return_value_len)(void *value), void (*print_value)(void *value, int len_to_print));
#endif