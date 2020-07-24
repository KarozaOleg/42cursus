/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:53:27 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 22:48:16 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	return_if_flag(char c)
{
	if (c == '-' || c == '0' || c == '.')
		return (c);
	return (0);
}

char	return_if_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X')
		return (c);
	return (0);
}
