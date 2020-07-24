/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_default_flag_minus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:32:08 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:02:59 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	handle_default_flag_minus(t_list *patterns, int *printed_lenght_of_tot)
{
	t_pattern *pattern;

	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag != '-')
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
