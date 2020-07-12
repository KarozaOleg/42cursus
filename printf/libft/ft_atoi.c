/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:16:29 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/14 14:02:34 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		is_negative;
	long	answer;
	int		i;

	is_negative = 0;
	answer = 0;
	i = 0;
	while (str[i] != 0 && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	while (str[i] != 0 && ft_isdigit(str[i]))
	{
		if (answer > answer * 10 + (str[i] - 48))
			return (is_negative ? 0 : -1);
		answer = answer * 10 + (str[i] - 48);
		++i;
	}
	if (is_negative)
		answer *= -1;
	return (answer);
}
