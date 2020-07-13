/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:24:13 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 22:35:08 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		wrapper_return_lenght_of_char(void *value)
{
	void *hello_moulinette;

	hello_moulinette = value;
	hello_moulinette += 0;
	return (1);
}

void	wrapper_ft_putchar_fd(void *value, int len_to_print)
{
	len_to_print = len_to_print;
	ft_putchar_fd(*((int *)value), 1);
}

int		handler_c(t_list *patterns, va_list argptr)
{
	t_printer_head printer_head;
	int value;

	value = va_arg(argptr, int);
	printer_head.ink = &value;
	printer_head.tape_measure = wrapper_return_lenght_of_char;
	printer_head.extruder = wrapper_ft_putchar_fd;	
	return (printer(patterns, &printer_head));
}