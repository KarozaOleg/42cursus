/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_single_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:51:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/22 22:41:00 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	printer_single_char(t_list *patterns, char c)
{
	int	printed_length_of_value;
	int	printed_lenght_of_total;

	printed_length_of_value = 1;
	printed_lenght_of_total = printed_length_of_value;
	handle_default_flag_empty(patterns, &printed_lenght_of_total);
	handle_default_flag_zero(patterns, &printed_lenght_of_total);
	ft_putchar_fd(c, 1);
	handle_default_flag_minus(patterns, &printed_lenght_of_total);
	return (printed_lenght_of_total);
}
