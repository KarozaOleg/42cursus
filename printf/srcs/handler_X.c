/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:47:52 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 22:32:31 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	wrapper_print_hexadecimal_X(void *value, int len_to_print)
{
	print_hexadecimal(*((int*)value), len_to_print, 1);
}

int		handler_X(t_list *patterns, va_list argptr)
{
	t_printer_head printer_head;	
	int value;
	
	value = va_arg(argptr, int);
	printer_head.ink = &value;
	printer_head.tape_measure = wrapper_return_lenght_of_int;
	printer_head.extruder = wrapper_print_hexadecimal_X;	
	return (printer(patterns, &printer_head));
}
