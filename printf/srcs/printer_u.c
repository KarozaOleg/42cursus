/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:52:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:38:18 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		return_length_of_uint(unsigned int value)
{
	if (value == 0)
		return (1);
	return (length_of_uint(value));
}

int		return_printed_length_of_uint(t_list *patterns, unsigned int value)
{
	t_pattern	*pattern;
	int			value_len;
	int			printed_value_lenght;

	value_len = return_length_of_uint(value);
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

void	ft_putunbr_fd(unsigned int value)
{
	if (value > 9)
		ft_putunbr_fd(value / 10);
	ft_putnbr_fd(value % 10, 1);
}

void	handle_u_flag_p(t_list *patterns, unsigned int value)
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
			if (pattern->precision > return_length_of_uint(value))
			{
				len = pattern->precision - return_length_of_uint(value);
				extruder_default('0', len);
			}
		}
	}
}

int		printer_u(t_list *patterns, va_list argptr)
{
	unsigned int	value;
	int				printed_length_of_value;
	int				printed_lenght_of_total;

	patterns += 0;
	value = va_arg(argptr, unsigned int);
	printed_length_of_value = return_printed_length_of_uint(patterns, value);
	printed_lenght_of_total = printed_length_of_value;
	handle_default_flag_empty(patterns, &printed_lenght_of_total);
	handle_d_i_u_x_flag_zero(patterns, &printed_lenght_of_total);
	handle_u_flag_p(patterns, value);
	if (printed_length_of_value > 0)
		ft_putunbr_fd(value);
	handle_default_flag_minus(patterns, &printed_lenght_of_total);
	return (printed_lenght_of_total);
}
