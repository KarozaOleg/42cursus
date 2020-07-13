/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:12:33 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 22:49:24 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	lenght_of_int(int nb)
{
	if(nb == 0)
		return 0;
	return (1 + lenght_of_int(nb / 10));
}

int	return_length_of_int(int nb)
{
	int is_negative;

	is_negative = 0;
	if(nb < 0)
		is_negative = 1;

	return (is_negative + lenght_of_int(nb));
}

int wrapper_return_lenght_of_int(void *value)
{
	return (return_length_of_int(*((int*)value)));
}

void wrapper_ft_putnbr(void *value, int len_to_print)
{
	len_to_print = len_to_print;
	ft_putnbr_fd(*((int*)value), 1);
}

int	handler_d_i(t_list *patterns, va_list argptr)
{
	t_printer_head t_printer_head;
	int value;

	value = va_arg(argptr, int);
	t_printer_head.ink = &value;
	t_printer_head.tape_measure = wrapper_return_lenght_of_int;
	t_printer_head.extruder = wrapper_ft_putnbr;	
	return (printer(patterns, &t_printer_head));
}