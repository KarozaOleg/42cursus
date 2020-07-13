/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:50:54 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 22:27:42 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_hexadecimal_ul(unsigned long int nb)
{
	char *base;

	base = "0123456789abcdef";
	if (nb >= 16)	
		print_hexadecimal_ul(nb / 16);		
	ft_putchar_fd(base[nb % 16], 1);
}

void	wrapper_print_hexadecimal_ul(void *value, int len_to_print)
{
	len_to_print = len_to_print;
	print_hexadecimal_ul(*((unsigned long int*)value));
}

int		handler_p(t_list *patterns, va_list argptr)
{
	t_printer_head printer_head;
	unsigned long int value;

	value = va_arg(argptr, unsigned long int);
	printer_head.ink = &value;
	printer_head.tape_measure = wrapper_return_lenght_of_int;
	printer_head.extruder = wrapper_print_hexadecimal_ul;	
	return (printer(patterns, &printer_head));
}
