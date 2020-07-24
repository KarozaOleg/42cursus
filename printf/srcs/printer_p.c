/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:51:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/23 15:37:20 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		return_length_of_ulint(unsigned long int value)
{
	if (value == 0)
		return (1);
	return (length_of_ulint(value));
}

int		return_printed_length_of_ulint(t_list *patter, unsigned long int value)
{
	t_pattern	*pattern;
	int			value_len;
	int			printed_value_lenght;

	value_len = return_length_of_ulint(value);
	printed_value_lenght = value_len;
	while (patter != NULL && (pattern = patter->content) != NULL)
	{
		patter = patter->next;
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

void	print_hexadecimal_uli(unsigned long int value)
{
	char *base;

	base = "0123456789abcdef";
	if (value >= 16)
		print_hexadecimal_uli(value / 16);
	ft_putchar_fd(base[value % 16], 1);
}

void	handle_p_flag_p(t_list *patterns, unsigned int value)
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
			if (pattern->precision > return_length_of_ulint(value))
			{
				len = pattern->precision - return_length_of_ulint(value);
				extruder_default('0', len);
			}
		}
	}
}

int		printer_p(t_list *patterns, va_list argptr)
{
	unsigned long int	value;
	int					printed_length_of_value;
	int					printed_lenght_of_total;

	patterns += 0;
	value = va_arg(argptr, unsigned long int);
	printed_length_of_value = return_printed_length_of_ulint(patterns, value);
	printed_lenght_of_total = printed_length_of_value + 2;
	handle_default_flag_empty(patterns, &printed_lenght_of_total);
	ft_putstr_fd("0x", 1);
	handle_p_flag_p(patterns, value);
	if (printed_length_of_value > 0)
		print_hexadecimal_uli(value);
	handle_default_flag_minus(patterns, &printed_lenght_of_total);
	return (printed_lenght_of_total);
}
