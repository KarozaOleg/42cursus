/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:16:39 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 22:28:13 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		return_str_len(void *value)
{
	char *str;
	int len;

	str = ((char*)value);
	len = 0;
	if(str != NULL)
	{
		while(*str != '\0')
		{
			++len;	
			str++;
		}
	}
	return (len);
}

void	wrapper_ft_putstr(void *value, int len_to_print)
{
	int str_len;
	int i;

	str_len = return_str_len(value);
	if(len_to_print < 0)
		len_to_print = str_len;
		
	i = 0;
	while(i < len_to_print && i < str_len)
	{
		ft_putchar_fd(((char *)value)[i], 1);
		++i;
	}
}

int		handler_s(t_list *patterns, va_list argptr)
{
	t_printer_head printer_head;
	char *value;	

	value = va_arg(argptr, char *);
	if (value == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (return_str_len("(null)"));
	}
	printer_head.ink = (void*)value;
	printer_head.tape_measure = return_str_len;
	printer_head.extruder = wrapper_ft_putstr;	
	return (printer(patterns, &printer_head));
}
		