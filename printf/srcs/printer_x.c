/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:51:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:44:36 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_hexadecimal(unsigned int value, int is_upper_case)
{
	int		shift_to_upper_case;
	char	*base;

	base = "0123456789abcdef";
	if (value >= 16)
		print_hexadecimal(value / 16, is_upper_case);
	shift_to_upper_case = 0;
	if (is_upper_case > 0 && value % 16 > 9 && value % 16 < 16)
		shift_to_upper_case = -32;
	ft_putchar_fd(base[value % 16] + shift_to_upper_case, 1);
}

int		return_length_of_x(unsigned int value)
{
	if (value == 0)
		return (1);
	return (length_of_x(value));
}

int		return_printed_length_of_x(t_list *patterns, unsigned int value)
{
	t_pattern	*pattern;
	int			value_len;
	int			printed_value_lenght;

	value_len = return_length_of_x(value);
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
			else if (pattern->precision == 0)
			{
				if (value == 0)
					printed_value_lenght = 0;
			}
		}
	}
	return (printed_value_lenght);
}

void	handle_x_flag_p(t_list *patterns, unsigned int value)
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
			if (pattern->precision > return_length_of_x(value))
			{
				len = pattern->precision - return_length_of_x(value);
				extruder_default('0', len);
			}
		}
	}
}

int		printer_x(t_list *patterns, va_list argptr, int is_upper_case)
{
	unsigned int	value;
	int				printed_length_of_value;
	int				printed_lenght_of_total;

	patterns += 0;
	value = va_arg(argptr, unsigned int);
	printed_length_of_value = return_printed_length_of_x(patterns, value);
	printed_lenght_of_total = printed_length_of_value;
	handle_default_flag_empty(patterns, &printed_lenght_of_total);
	handle_d_i_u_x_flag_zero(patterns, &printed_lenght_of_total);
	handle_x_flag_p(patterns, value);
	if (printed_length_of_value > 0)
		print_hexadecimal(value, is_upper_case);
	handle_default_flag_minus(patterns, &printed_lenght_of_total);
	return (printed_lenght_of_total);
}
