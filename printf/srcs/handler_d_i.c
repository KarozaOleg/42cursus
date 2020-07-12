/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:12:33 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/12 22:03:25 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void wrapper_ft_putnbr(void *value, int len_to_print)
{
	ft_putnbr_fd(*((int*)value), 0);
}

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

void	handler_d_i(char flag, int precision, va_list argptr)
{
	int value;

	value = va_arg(argptr, int);
	printer(flag, precision, (void*)&value, wrapper_return_lenght_of_int, wrapper_ft_putnbr);
}