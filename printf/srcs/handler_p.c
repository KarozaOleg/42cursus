/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:50:54 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/12 22:03:54 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_hexadecimal_ul(unsigned long int nb)
{
	char *base;

	base = "0123456789abcdef";
	if (nb >= 16)	
		print_hexadecimal_ul(nb / 16);		
	ft_putchar_fd(base[nb % 16], 0);
}

void	wrapper_print_hexadecimal_ul(void *value, int len_to_print)
{
	print_hexadecimal_ul(*((unsigned long int*)value));
}

void	handler_p(char flag, int precision, va_list argptr)
{
	unsigned long int value;

	value = va_arg(argptr, unsigned long int);
	ft_putstr_fd("0x", 0);
	printer(flag, precision, (void*)&value, wrapper_return_lenght_of_int, wrapper_print_hexadecimal_ul);
}
