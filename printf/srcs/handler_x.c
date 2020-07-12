/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:47:52 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/12 22:03:38 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_hexadecimal(int nb, int len_to_print, int is_upper_case)
{
	int		shift_to_upper_case;
	char	*base;	
		
	base = "0123456789abcdef";
	if (nb >= 16)	
		print_hexadecimal(nb / 16, len_to_print, is_upper_case);	
		
	shift_to_upper_case = 0;
	if(is_upper_case > 0 && nb % 16 > 9 && nb % 16 < 16)
		shift_to_upper_case = -32;

	ft_putchar_fd(base[nb % 16] + shift_to_upper_case, 0);
}

void	wrapper_print_hexadecimal_X(void *value, int len_to_print)
{
	print_hexadecimal(*((int*)value), len_to_print, 1);
}
void	wrapper_print_hexadecimal_x(void *value, int len_to_print)
{	
	print_hexadecimal(*((int*)value), len_to_print, 0);
}

void	handler_x(char flag, int precision, char conversation, va_list argptr)
{
	int value;
	void (*printvalue)(void *value, int len_to_print);

	if(conversation == 'x')
		printvalue = wrapper_print_hexadecimal_x;
	else
		printvalue = wrapper_print_hexadecimal_X;
		
	value = va_arg(argptr, int);
	printer(flag, precision, (void*)&value, wrapper_return_lenght_of_int, printvalue);
}
