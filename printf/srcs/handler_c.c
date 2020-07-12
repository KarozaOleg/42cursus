/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:24:13 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/12 22:03:44 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	wrapper_ft_putchar_fd(void *value, int len_to_print)
{
	ft_putchar_fd(*((int *)value), 0);
}

int		wrapper_return_len_c(void *value)
{
	void *hello_moulinette;

	hello_moulinette = value;
	hello_moulinette += 0;
	return (1);
}

void	handler_c(char flag, int precision, va_list argptr)
{
	int value;

	value = va_arg(argptr, int);
	printer(flag, precision, (void*)&value, wrapper_return_len_c, wrapper_ft_putchar_fd);
}