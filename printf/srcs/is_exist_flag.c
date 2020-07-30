/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:27:06 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/25 18:01:29 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	return_is_exist_flag(t_list *patterns, char flag)
{
	t_pattern *pattern;

	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag == flag)
			return (1);
	}
	return (0);
}

int	return_is_exist_flag_zero(t_list *patterns)
{
	return (return_is_exist_flag(patterns, '0'));
}

int	return_is_exist_flag_p(t_list *patterns)
{
	return (return_is_exist_flag(patterns, '.'));
}

int	return_is_exist_flag_zero_and_p(t_list *patterns)
{
	if (return_is_exist_flag_zero(patterns) < 1)
		return (0);
	if (return_is_exist_flag_p(patterns) < 1)
		return (0);
	return (1);
}

int	return_is_exist_flag_zero_and_minus(t_list *patterns)
{
	if (return_is_exist_flag_zero(patterns) < 1)
		return (0);
	if (return_is_exist_flag(patterns, '-') < 1)
		return (0);
	return (1);
}
