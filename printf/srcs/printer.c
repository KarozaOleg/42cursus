/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:54:12 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 23:11:00 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	extruder_default(char symbol_to_print, int amount)
{	
	while (amount-- > 0)
		ft_putchar_fd(symbol_to_print, 1);
}

void	handle_patterns_before_print(t_list *patterns, int *value_len)
{
	t_pattern *pattern;

	pattern = patterns->content;
	
	if(pattern->flag == 0 && pattern->precision > 0)	
	{
		if(*value_len < pattern->precision)
		{
			pattern->precision -= pattern->precision - *value_len;
			extruder_default(' ', pattern->precision);
		}
	}
}

int		printer(t_list *patterns, t_printer_head *printer_head)
{
	int value_len;
	int printed;	


	value_len = printer_head->tape_measure(printer_head->ink);
	printed = value_len;
	
	handle_patterns_before_print(patterns, &value_len);

	printer_head->extruder(printer_head->ink, value_len);
	
	return (printed);		
}

// patterns+=0;
	// printer_head+=0;

	// return (0);
	/*
	int printed;
	int value_len;
	
	value_len = printer_head->tape_measure(printer_head->ink);
	printed = value_len;

	if(pattern->flag == '.' && pattern->precision < value_len)
	{
		printed -= value_len - pattern->precision;
		value_len -= value_len - pattern->precision;
	}

	if(pattern->amount_whitespaces > value_len)
	{
		printed += pattern->amount_whitespaces - value_len;
		extruder_default(' ', pattern->amount_whitespaces - value_len);
	}	

	printer_ink->print_value(printer_ink->value, value_len);

	if(pattern->flag == '-' && pattern->precision > value_len)
	{
		printed += pattern->precision - value_len;
		extruder_default(' ', pattern->precision - value_len);
	}

	*/

/*
	if(pattern->flag == '.' && pattern->precision == 0)
		amount_print_from_value = 0;
	else if(pattern->flag > 0 && pattern->precision > 0)	
	{
		if(amount_print_from_value >= pattern->precision)
		{
			if(pattern->flag == '.')
				amount_print_from_value -= (amount_print_from_value - pattern->precision);
			pattern->precision = 0;
		}
	}	

	if(pattern->precision > 0)
	{
		if(amount_print_from_value <= pattern->precision)		
			pattern->precision -= amount_print_from_value;
		else
			pattern->precision = 0;
	}

	if(pattern->flag == 0 && pattern->precision > 0)
	{
		amount_printed += pattern->precision;
		handle_precision(pattern->flag, &(pattern->precision));
	}
	else if(pattern->flag == '0' && pattern->precision > 0)
	{
		// answer -= precision;
		handle_precision(pattern->flag, &(pattern->precision));
	}

	printer_ink->print_value(printer_ink->value, amount_print_from_value);
	
	if(pattern->flag == '-' && pattern->precision > 0)
	{
		amount_printed += pattern->precision;
		handle_precision(pattern->flag, &(pattern->precision));
	}
	return (amount_printed);
	*/