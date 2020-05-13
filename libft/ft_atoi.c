/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:16:29 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/13 15:34:56 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long int	isNegative;
	long long int	answer;

	i = 0;
	isNegative = 0;
	answer = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isNegative = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			break;	
		answer *= 10;
		answer += (long long int)(str[i] - 48);
		i++;
	}
	if(isNegative)
		answer *= -1;
	return (answer);
}