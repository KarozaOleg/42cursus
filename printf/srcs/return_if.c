/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:53:27 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/25 20:53:25 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	return_if_flag(char c)
{
	if (c == '0' || c == '-' || c == '.')
		return (c);
	return (0);
}

char	handle_flag(int *i, const char *str)
{
	char	flag;

	flag = 0;
	if (str[*i] == '0')
	{
		flag = '0';
		(*i)++;
		while (str[*i] == '0')
			(*i)++;
	}
	else if (str[*i] == '-')
	{
		flag = '-';
		(*i)++;
		while (str[*i] == '-' || str[*i] == '0')
			(*i)++;
	}
	else if (str[*i] == '.')
	{
		flag = '.';
		(*i)++;
	}
	return (flag);
}

char	return_if_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X')
		return (c);
	return (0);
}
