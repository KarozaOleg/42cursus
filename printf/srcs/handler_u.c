/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:04:48 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/12 22:04:12 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putunbr_fd(unsigned int nb, int fd)
{
	if(nb > (unsigned int)9)
		ft_putunbr_fd(nb / 10, fd);
	ft_putnbr_fd(nb % 10, fd);
}

void	wrapper_ft_putunbr(void *value, int len_to_print)
{
	ft_putunbr_fd(*((unsigned int*)value), 0);
}

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

int	wrapper_return_length_of_uint(void *value)
{
	return (return_length_of_uint(*((unsigned int*)value)));
}

void	handler_u(char flag, int precision, va_list argptr)
{
	unsigned int value;

	value = va_arg(argptr, unsigned int);
	printer(flag, precision, (void*)&value, wrapper_return_length_of_uint, wrapper_ft_putunbr);
}