/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_patterns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:47:05 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/24 14:28:21 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		free_patterns(t_list **patterns)
{
	ft_lstclear(patterns, free);
	*patterns = NULL;
	return (1);
}

int		initialize_pattern_to_zero(t_pattern **pattern)
{
	*pattern = malloc(sizeof(t_pattern));
	if (*pattern == NULL)
		return (-1);
	(*(pattern))->flag = 0;
	(*(pattern))->precision = 0;
	return (0);
}

int		parse_patterns(int *i, const char *str, t_list **patter, va_list argptr)
{
	t_pattern *pattern;

	while (str[*i] != '%' && str[*i] != '\0')
	{
		if (initialize_pattern_to_zero(&pattern) < 0)
			return (-1);
		pattern->flag = return_if_flag(str[*i]);
		if (pattern->flag > 0)
			++(*i);
		if (str[*i] == '*')
		{
			pattern->precision = va_arg(argptr, int);
			++(*i);
		}
		else if (ft_isdigit(str[*i]))
		{
			pattern->precision = ft_atoi(&str[*i]);
			while (ft_isdigit(str[*i]))
				++(*i);
		}
		ft_lstadd_back(patter, ft_lstnew(pattern));
		if (return_if_flag(str[*i]) == 0)
			break ;
	}
	return (0);
}
