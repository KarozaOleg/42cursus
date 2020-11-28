/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:16:29 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 14:50:53 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sprite/sprite_utils.h"

int			return_texture_color_sprite(t_image *image, int size, int x, int y)
{
	int texture_x;
	int texture_y;
	int color;

	texture_x = x * 64 / size;
	texture_y = y * 64 / size;
	color = return_texture_color(image, texture_x, texture_y);
	return (color);
}
