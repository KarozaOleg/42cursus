/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 13:15:57 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/13 14:56:45 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int return_amount_symbols(int n)
{
	int amount;

	amount = 1;
	if(n < 0)
		++amount;
	while(n > 9 || n < -9)
	{
		n /= 10;
		++amount;
	}
	return (amount);
}

static int return_abs(int n)
{
	if(n < 0)
		n *= -1;
	return (n);
}

char *ft_itoa(int n)
{
	int amount;
	char *str;

	amount = return_amount_symbols(n);
	str = malloc((amount + 1) * sizeof(char));	
	if(str == NULL)
		return (NULL);
	if(n < 0)
		str[0] = '-';
	str[amount] = 0;
	while(amount > 0)
	{
		str[--amount] = return_abs(n % 10) + 48;
		n /= 10;
		if(n == 0)
			break;
	}
	return (str);
}