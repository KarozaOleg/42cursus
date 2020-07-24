/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 22:46:36 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 22:47:00 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		printer(char conversation, t_list *patterns, va_list argptr)
{
	if (conversation == 'c')
		return (printer_c(patterns, argptr));
	else if (conversation == 's')
		return (printer_s(patterns, argptr));
	else if (conversation == 'p')
		return (printer_p(patterns, argptr));
	else if (conversation == 'd' || conversation == 'i')
		return (printer_d_i(patterns, argptr));
	else if (conversation == 'u')
		return (printer_u(patterns, argptr));
	else if (conversation == 'x')
		return (printer_x(patterns, argptr, 0));
	else if (conversation == 'X')
		return (printer_x(patterns, argptr, 1));
	return (0);
}
