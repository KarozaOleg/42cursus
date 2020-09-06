/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:24:12 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 11:46:23 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/colors.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		return_white()
{
	return (create_trgb(0, 255, 255, 255));
}

int		return_red()
{
	return (create_trgb(0, 255, 45, 0));
}

