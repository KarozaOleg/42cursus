/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist_flag2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:27:06 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 21:08:16 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	return_is_exist_flag_zero_and_negative(t_list *patterns)
{
	t_pattern *pattern;

	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag != '0')
			continue;
		if (pattern->precision < 0)
			return (1);
		break ;
	}
	return (0);
}

int	return_is_exist_flag_zero_and_zero(t_list *patterns)
{
	t_pattern *pattern;

	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag != '0')
			continue;
		if (pattern->precision == 0)
			return (1);
		break ;
	}
	return (0);
}

int	return_is_exist_flag_p_and_negative(t_list *patterns)
{
	t_pattern *pattern;

	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag != '.')
			continue;
		if (pattern->precision < 0)
			return (1);
		break ;
	}
	return (0);
}

int	return_is_exist_flag_p_precision(t_list *patterns)
{
	t_pattern *pattern;

	while (patterns != NULL && (pattern = patterns->content) != NULL)
	{
		patterns = patterns->next;
		if (pattern->flag != '.')
			continue;
		return (pattern->precision);
	}
	return (-1);
}
