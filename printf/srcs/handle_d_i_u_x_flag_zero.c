/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_i_u_x_flag_zero.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:50:06 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 20:59:40 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_case1(int precision, int *printed_lenght_of_total, int *len)
{
	if (precision > *printed_lenght_of_total)
	{
		*len = precision - *printed_lenght_of_total;
		extruder_default(' ', *len);
		*printed_lenght_of_total += *len;
	}
}

void	print_case2(int precision, int *printed_lenght_of_total, int *len)
{
	precision *= -1;
	if (precision > *printed_lenght_of_total)
	{
		*len = precision - *printed_lenght_of_total;
		extruder_default(' ', *len);
		*printed_lenght_of_total += *len;
	}
}

void	print_case3(int precision, int *printed_lenght_of_total, int *len)
{
	if (precision > *printed_lenght_of_total)
	{
		*len = precision - *printed_lenght_of_total;
		extruder_default('0', *len);
		*printed_lenght_of_total += *len;
	}
}

void	handle_d_i_u_x_flag_zero(t_list *patterns, int *printed_lenght_of_total)
{
	t_pattern	*pattern;
	int			p_precision;
	int			len;

	p_precision = return_is_exist_flag_p_precision(patterns);
	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag != '0')
			continue;
		if (p_precision > -1 && p_precision < pattern->precision)
			print_case1(pattern->precision, printed_lenght_of_total, &len);
		else if (pattern->precision < 0)
			print_case2(pattern->precision, printed_lenght_of_total, &len);
		else
			print_case3(pattern->precision, printed_lenght_of_total, &len);
	}
}
