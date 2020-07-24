/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:51:26 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:10:24 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	return_printed_length_of_c(char c)
{
	c += 0;
	return (1);
}

int	printer_c(t_list *patterns, va_list argptr)
{
	char	value;
	int		printed_length_of_value;
	int		printed_lenght_of_total;

	patterns += 0;
	value = va_arg(argptr, int);
	printed_length_of_value = return_printed_length_of_c(value);
	printed_lenght_of_total = printed_length_of_value;
	if (return_is_exist_flag_empty_and_negative(patterns) == 0)
		handle_default_flag_empty(patterns, &printed_lenght_of_total);
	ft_putchar_fd(value, 1);
	if (return_is_exist_flag_empty_and_negative(patterns))
		handle_default_flag_empty(patterns, &printed_lenght_of_total);
	handle_default_flag_minus(patterns, &printed_lenght_of_total);
	return (printed_lenght_of_total);
}
