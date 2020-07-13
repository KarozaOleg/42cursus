/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:32:15 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 22:32:27 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_hexadecimal(int nb, int len_to_print, int is_upper_case)
{
	int		shift_to_upper_case;
	char	*base;	
		
	base = "0123456789abcdef";
	if (nb >= 16)	
		print_hexadecimal(nb / 16, len_to_print, is_upper_case);	
		
	shift_to_upper_case = 0;
	if(is_upper_case > 0 && nb % 16 > 9 && nb % 16 < 16)
		shift_to_upper_case = -32;

	ft_putchar_fd(base[nb % 16] + shift_to_upper_case, 1);
}