/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:24:12 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/29 19:01:51 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/colors.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		return_black()
{
	return (create_trgb(0, 0, 0, 0));
}

int		return_white()
{
	return (create_trgb(0, 255, 255, 255));
}

int		return_red()
{
	return (create_trgb(0, 255, 45, 0));
}

int		return_magenta()
{
	return (create_trgb(0, 255, 0, 255));
}

int		return_yellow()
{
	return (create_trgb(0, 252, 186, 3));
}

int		return_up()
{
	return (create_trgb(0, 50, 46, 44));
}

int		return_down()
{
	return (create_trgb(0, 118, 112, 106));
}
