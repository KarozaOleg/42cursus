/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_single_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:51:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/25 20:55:40 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	handle_single_char_flag_zero(t_list *pat, int *printed_lenght_of_tot)
{
	t_pattern	*pattern;

	while (pat != NULL && (pattern = pat->content) != NULL)
	{
		pat = pat->next;
		if (pattern->flag != '0')
			continue;
		if (pattern->precision < 0)
			pattern->precision *= -1;
		if (pattern->precision > *printed_lenght_of_tot)
		{
			pattern->precision -= *printed_lenght_of_tot;
			*printed_lenght_of_tot += pattern->precision;
			extruder_default(' ', pattern->precision);
		}
	}
}

int		printer_single_char(t_list *patterns, char c)
{
	int	printed_length_of_value;
	int	printed_lenght_of_total;

	printed_length_of_value = 1;
	printed_lenght_of_total = printed_length_of_value;
	handle_default_flag_empty(patterns, &printed_lenght_of_total);
	if (return_is_exist_flag_zero_and_negative(patterns) == 0)
		handle_default_flag_zero(patterns, &printed_lenght_of_total);
	ft_putchar_fd(c, 1);
	if (return_is_exist_flag_zero_and_negative(patterns) == 1)
		handle_single_char_flag_zero(patterns, &printed_lenght_of_total);
	handle_default_flag_minus(patterns, &printed_lenght_of_total);
	return (printed_lenght_of_total);
}
