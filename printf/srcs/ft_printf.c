/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 21:15:57 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 23:16:25 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	return_if_flag(char c)
{
	if(c == '-' || c == '0' || c == '.')
		return (c);
	return (0);
}

char	return_if_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (c);
	return (0);
}

int		handler(char conversation, t_list *patterns, va_list argptr)
{	
	if(conversation == 'c')	
		return (handler_c(patterns, argptr));
	else if(conversation == 's')
		return (handler_s(patterns, argptr));
	else if(conversation == 'p')
		return (handler_p(patterns, argptr));
	else if(conversation == 'd' || conversation == 'i')		
		return (handler_d_i(patterns, argptr));	
	else if(conversation == 'u')
		return (handler_u(patterns, argptr));
	else if(conversation == 'x')
		return (handler_x(patterns, argptr));	
	else if(conversation == 'X')
		return (handler_X(patterns, argptr));
	return (0);
}

void	initialize_to_zero(t_pattern *pattern)
{
	pattern->flag = 0;
	pattern->precision = 0;
}

/*
int	return_pattern(int i, const char *str, t_pattern *pattern, va_list argptr)
{	
	if (str[i] != '%')
		return (i);	
	++i;
					
	if (str[i] == '*')
	{
		pattern->amount_whitespaces = va_arg(argptr, int);
		++i;
	}
	else if (ft_isdigit(str[i]))
	{				
		pattern->amount_whitespaces = ft_atoi(&str[i]);
		while (ft_isdigit(str[i]))
			++i;
	}

	pattern->flag = return_is_flag(str[i]);
	if (pattern->flag > 0)			
		++i;				
				
	if (str[i] == '*')
	{
		pattern->precision = va_arg(argptr, int);
		++i;
	}
	else if (ft_isdigit(str[i]))
	{
		pattern->precision = ft_atoi(&str[i]);
		while(ft_isdigit(str[i]))
			++i;	
	}
	
	pattern->conversation = return_is_conversion(str[i]);
	
	return (i);
}
*/

void	print_pattern(void *pattern)
{
	printf("\nf:%c\n", ((t_pattern *)pattern)->flag);
	printf("p:%d\n", ((t_pattern *)pattern)->precision);
}

int		parse_patterns(int *i, const char *str, t_list **patterns, va_list argptr)
{
	t_pattern *pattern;			
	
	while (str[*i] != '\0' && return_if_conversion(str[*i]) == 0)
	{		
		pattern = malloc(sizeof(t_pattern *));
		if (pattern == NULL)
			return (-1);
			
		initialize_to_zero(pattern);
		
		pattern->flag = return_if_flag(str[*i]);
		if(pattern->flag > 0)
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
		ft_lstadd_back(patterns, ft_lstnew(pattern));
		if(pattern->flag == 0 && pattern->precision == 0)
			break;
	}
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list argptr;
	t_list *patterns;
	int printed;
	int conversion;
	int i;
		
	patterns = NULL;
	printed = 0;
	i = 0;	
	va_start(argptr, str);
	while(str[i] != '\0')
	{
		if(str[i] == '%')
		{
			++i;			
			if(parse_patterns(&i, str, &patterns, argptr) < 0)
			{
				printed = -1;
				break;
			}
			conversion = return_if_conversion(str[i]);
			if (conversion > 0)			
			{
				printed += handler(conversion, patterns, argptr);
				++i;
			}							
			ft_lstiter(patterns, free);
			if(conversion > 0)
				continue;
		}
		++printed;
		ft_putchar_fd(str[i], 1);
		++i;
	}	
	va_end(argptr);
	return (printed);
}


// initialize_to_zero(&pattern);
		
// i = return_pattern(i, str, &pattern, argptr);
		
// // printf("\nw:%d\n", pattern.amount_whitespaces);
// // printf("f:%c\n", pattern.flag);
// // printf("p:%d\n", pattern.precision);
// // printf("c:%c\n", pattern.conversation);
		
// if(pattern.conversation > 0)		
// 	amount_printed += handler(&pattern, argptr);		
// else
// {
// 	++amount_printed;
// 	ft_putchar_fd(str[i], 1);	
// }
// ++i;