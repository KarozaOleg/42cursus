/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:20:48 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:46:20 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	lenght_of_int(int nb)
{
	if (nb == 0)
		return (0);
	return (1 + lenght_of_int(nb / 10));
}

int	length_of_ulint(unsigned long int value)
{
	if (value == 0)
		return (0);
	return (1 + length_of_ulint(value / 16));
}

int	length_of_uint(unsigned int value)
{
	if (value == 0)
		return (0);
	return (1 + length_of_uint(value / 10));
}

int	length_of_x(unsigned int value)
{
	if (value < 16)
		return (1);
	return (1 + length_of_x(value / 16));
}
