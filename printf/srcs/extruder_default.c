/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extruder_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:37:08 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 20:42:02 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	extruder_default(char symbol_to_print, int amount)
{
	while (amount-- > 0)
		ft_putchar_fd(symbol_to_print, 1);
}
