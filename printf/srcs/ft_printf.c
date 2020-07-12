/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 21:15:57 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/12 22:08:00 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	return_is_flag(char c)
{
	if(c == '-' || c == '0' || c == '.')
		return (c);
	return (0);
}

char	return_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (c);
	return (0);
}

void	handle_precision(char flag, int precision)
{
	char symbol_to_print;

	if(precision < 1)
		return;

	symbol_to_print = '0';
	if(flag == '-')
		symbol_to_print = ' ';
		
	while(precision-- > 0)
		ft_putchar_fd(symbol_to_print, 0);
}

void	printer(int flag, int precision, void *value, int (*return_value_len)(void *value), void (*print_value)(void *value, int len))
{
	int value_len;	

	if(precision > 0)
	{
		value_len = return_value_len(value);
		if(value_len < precision)		
			precision -= value_len;			
	}

	if(flag == '0' && precision > 0)
		handle_precision(flag, precision);

	print_value(value, precision);
	
	if(flag == '-' && precision > 0)
		handle_precision(flag, precision);
}

void	handler(char flag, int precision, char conversation, va_list argptr)
{	
	if(conversation == 'c')	
		handler_c(flag, precision, argptr);
	else if(conversation == 's')
		handler_s(flag, precision, argptr);
	else if(conversation == 'p')
		handler_p(flag, precision, argptr);		
	else if(conversation == 'd' || conversation == 'i')		
		handler_d_i(flag, precision, argptr);		
	else if(conversation == 'u')
		handler_u(flag, precision, argptr);
	else if(conversation == 'x' || conversation == 'X')
		handler_x(flag, precision, conversation, argptr);
}

int ft_printf(const char *str, ...)
{
	va_list argptr;
	char flag;
	int precision;
	char conversation;
	int i;
	
	i = 0;	
	va_start(argptr, str);
	while(str[i] != '\0')
	{
		flag = 0;
		precision = 0;
		conversation = 0;
		if(str[i] == '%')
		{
			++i;
			flag = return_is_flag(str[i]);
			if(flag > 0)
			{
				++i;
				if(str[i] == '*')
				{
					precision = va_arg(argptr, int);
					++i;
				}
				else if(str[i] > 47 && str[i] < 58)
				{
					precision = ft_atoi(&str[i]);
					i += return_length_of_int(precision);	
				}
			}	
			conversation = return_is_conversion(str[i]);				
		}
		if(conversation > 0)		
			handler(flag, precision, conversation, argptr);		
		else
			ft_putchar_fd(str[i], 0);	
		++i;
	}
	
	va_end(argptr);
	//TODO need return amount of printed characters
	return (0);
}

// int main()
// {
// 	char *test ="123";
	
// 	printf("%.*s\n", 0, "12345");
// 	ft_printf("%.*s\n", 0, "12345");
// 	return 0;
// }