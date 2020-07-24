/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_default_flag_empty.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:26:43 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:01:49 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	handle_default_flag_empty(t_list *patterns, int *printed_lenght_of_tot)
{
	t_pattern *pattern;

	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag != 0)
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
