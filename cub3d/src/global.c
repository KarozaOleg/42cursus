/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:42:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/22 17:43:48 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.h"

void	ft_putstr(char *str)
{
	ft_putstr_fd(str, 0);
}