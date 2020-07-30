/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_multiply_patterns.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:02:12 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/25 20:52:30 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	handle_multiply_patterns(t_list *patterns)
{
	t_pattern *pattern;

	if (return_is_exist_flag_zero_and_minus(patterns))
	{
		while (patterns != NULL && (pattern = patterns->content) != NULL)
		{
			patterns = patterns->next;
			if (pattern->flag != '0')
				continue;
			pattern->flag = -1;
			pattern->precision = 0;
		}
	}
}
