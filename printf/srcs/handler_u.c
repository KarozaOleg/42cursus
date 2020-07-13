/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:04:48 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 22:29:25 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		lenght_of_uint(unsigned int nb)
{
	if(nb == 0)
		return 0;
	return (1 + lenght_of_uint(nb / 10));
}

int		return_length_of_uint(unsigned int nb)
{
	if(nb == 0)
		return 0;
	return (1 + lenght_of_uint(nb / 10));
}

int		wrapper_return_length_of_uint(void *value)
{
	return (return_length_of_uint(*((unsigned int*)value)));
}

void	ft_putunbr_fd(unsigned int nb)
{
	if (nb > (unsigned int)9)
		ft_putunbr_fd(nb / 10);
	ft_putnbr_fd(nb % 10, 1);
}

void	wrapper_ft_putunbr(void *value, int len_to_print)
{
	len_to_print = len_to_print;
	ft_putunbr_fd(*((unsigned int*)value));
}

int		handler_u(t_list *patterns, va_list argptr)
{
	t_printer_head printer_head;
	unsigned int value;

	value = va_arg(argptr, unsigned int);
	printer_head.ink = &value;
	printer_head.tape_measure = wrapper_return_length_of_uint;
	printer_head.extruder = wrapper_ft_putunbr;	
	return (printer(patterns, &printer_head));
}