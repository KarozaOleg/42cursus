/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 21:15:57 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/24 14:28:27 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	skip_all_spaces(int *i, int *printed, t_list *patterns, const char *str)
{
	++(*i);
	while (str[*i] == ' ')
	{
		*printed += printer_single_char(patterns, str[*i]);
		++(*i);
		while (str[*i] == ' ')
			++(*i);
	}
}

void	hello_norminette(t_list **patterns, int *printed, int *i)
{
	*patterns = NULL;
	*printed = 0;
	*i = 0;
}

int		bye_norminette(va_list argptr, t_list **patterns, int printed)
{
	va_end(argptr);
	free_patterns(patterns);
	return (printed);
}

int		print_case(char c, int *printed, t_list *patterns, va_list argptr)
{
	int conversion;

	conversion = return_if_conversion(c);
	if (conversion > 0)
		*printed += printer(conversion, patterns, argptr);
	return (conversion);
}

int		ft_printf(const char *str, ...)
{
	va_list	argptr;
	t_list	*patterns;
	int		printed;
	int		convers;
	int		i;

	hello_norminette(&patterns, &printed, &i);
	va_start(argptr, str);
	while (str[i] != '\0' && (convers = 0) == 0 && free_patterns(&patterns))
	{
		if (str[i] == '%')
		{
			skip_all_spaces(&i, &printed, patterns, str);
			if (parse_patterns(&i, str, &patterns, argptr) < 0)
			{
				printed = -1;
				break ;
			}
			if ((convers = print_case(str[i], &printed, patterns, argptr)) > 0)
				++i;
		}
		if (convers < 1 && str[i] != '\0')
			printed += printer_single_char(patterns, str[i++]);
	}
	return (bye_norminette(argptr, &patterns, printed));
}
