/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:50:14 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:32:09 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		return_printed_length_of_str(t_list *patterns, char *value)
{
	t_pattern	*pattern;
	int			value_len;
	int			printed_value_lenght;

	value_len = (int)ft_strlen(value);
	printed_value_lenght = value_len;
	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag == '.')
		{
			if (pattern->precision == 0)
				printed_value_lenght = 0;
			else if (pattern->precision > 0)
			{
				if (pattern->precision < value_len)
					printed_value_lenght -=
					printed_value_lenght - pattern->precision;
			}
		}
	}
	return (printed_value_lenght);
}

void	wrapper_ft_putstr_fd(char *value, int printed_length_of_value)
{
	int i;

	i = 0;
	while (value[i] != '\0' && i < printed_length_of_value)
	{
		ft_putchar_fd(value[i], 1);
		++i;
	}
}

int		printer_s(t_list *patterns, va_list argptr)
{
	char	*value;
	int		printed_length_of_value;
	int		printed_lenght_of_total;

	value = va_arg(argptr, char *);
	if (value == NULL)
		value = "(null)";
	printed_length_of_value = return_printed_length_of_str(patterns, value);
	printed_lenght_of_total = printed_length_of_value;
	if (return_is_exist_flag_empty_and_negative(patterns) == 0)
		handle_default_flag_empty(patterns, &printed_lenght_of_total);
	handle_default_flag_zero(patterns, &printed_lenght_of_total);
	wrapper_ft_putstr_fd(value, printed_length_of_value);
	if (return_is_exist_flag_empty_and_negative(patterns) == 1)
		handle_default_flag_empty(patterns, &printed_lenght_of_total);
	handle_default_flag_minus(patterns, &printed_lenght_of_total);
	return (printed_lenght_of_total);
}
