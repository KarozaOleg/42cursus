/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:51:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:21:02 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		return_lenght_of_int(int value, int skip_minus)
{
	int is_negative;

	if (value == 0)
		return (1);
	is_negative = 0;
	if (value < 0)
		is_negative = 1;
	is_negative = (is_negative == 1 && skip_minus == 0 ? 1 : 0);
	return (is_negative + lenght_of_int(value));
}

int		return_printed_length_of_int(t_list *patterns, int value)
{
	t_pattern	*pattern;
	int			value_len;
	int			printed_value_lenght;

	value_len = return_lenght_of_int(value, 1);
	printed_value_lenght = value_len;
	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag == '.')
		{
			if (pattern->precision > 0)
			{
				if (pattern->precision > value_len)
					printed_value_lenght += pattern->precision - value_len;
			}
			else if (pattern->precision == 0 && value == 0)
				printed_value_lenght = 0;
		}
	}
	if (value < 0)
		++printed_value_lenght;
	return (printed_value_lenght);
}

void	handle_d_i_flag_p(t_list *patterns, int value)
{
	t_pattern	*pattern;
	int			len;

	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag != '.')
			continue;
		if (pattern->precision > 0)
		{
			if (pattern->precision > return_lenght_of_int(value, 1))
			{
				len = pattern->precision - return_lenght_of_int(value, 1);
				extruder_default('0', len);
			}
		}
	}
}

void	wrapper_ft_putnbr_fd(int value)
{
	if (value == -2147483648)
		ft_putstr_fd("2147483648", 1);
	else
	{
		if (value < 0)
			value *= -1;
		ft_putnbr_fd(value, 1);
	}
}

int		printer_d_i(t_list *patterns, va_list argptr)
{
	int	value;
	int	printed_lenght_of_total;

	value = va_arg(argptr, int);
	printed_lenght_of_total = return_printed_length_of_int(patterns, value);
	if (return_is_exist_flag_empty_and_negative(patterns) == 0)
		handle_default_flag_empty(patterns, &printed_lenght_of_total);
	if (value < 0 && (return_is_exist_flag_zero_and_p(patterns) == 0 ||
						return_is_exist_flag_p_and_negative(patterns)))
		ft_putchar_fd('-', 1);
	if (return_is_exist_flag_zero_and_negative(patterns) == 0)
		handle_d_i_u_x_flag_zero(patterns, &printed_lenght_of_total);
	if (value < 0 && (return_is_exist_flag_zero_and_p(patterns) &&
						return_is_exist_flag_p_and_negative(patterns) == 0))
		ft_putchar_fd('-', 1);
	handle_d_i_flag_p(patterns, value);
	if (return_printed_length_of_int(patterns, value) > 0)
		wrapper_ft_putnbr_fd(value);
	if (return_is_exist_flag_empty_and_negative(patterns) == 1)
		handle_default_flag_empty(patterns, &printed_lenght_of_total);
	if (return_is_exist_flag_zero_and_negative(patterns) == 1)
		handle_d_i_u_x_flag_zero(patterns, &printed_lenght_of_total);
	handle_default_flag_minus(patterns, &printed_lenght_of_total);
	return (printed_lenght_of_total);
}
