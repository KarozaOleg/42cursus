/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 13:40:09 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/draw.h"

void	draw_scaled_point(t_mlx_my *mlx_my, int x_shifted, int y_shifted, int increase_to, int color)
{
	int y = y_shifted;
	int y_amount = 0;
	while(y_amount < increase_to)
	{
		int x = x_shifted;
		int x_amount = 0;
		while(x_amount < increase_to)
		{
			my_mlx_pixel_put(mlx_my->scene, x, y, color);
			x_amount += 1;
			x += 1;
		}
		y_amount += 1;
		y += 1;
	}
}

void	draw_map(t_mlx_my *mlx_my, int **map)
{
	int increase_to = 50;
	
	int x_shifted = 0;
	int y_shifted = 0;
	
	int y_map = 0;
	while(map[y_map] != NULL)
	{
		int x_map = 0;
		while(map[y_map][x_map] > -1)
		{
			if(map[y_map][x_map] == 1)
				draw_scaled_point(mlx_my, x_shifted, y_shifted, increase_to, return_white());
			x_shifted += increase_to;
			x_map += 1;
		}
		x_shifted = 0;
		y_shifted += increase_to;
		y_map += 1;
	}
	mlx_put_image_to_window(mlx_my->mlx, mlx_my->win, mlx_my->scene->img, 0, 0);
}

void	draw_player(t_mlx_my *mlx_my, t_player *player)
{
	mlx_my += 0;
	player += 0;
}

void	draw_the_line(t_mlx_my *mlx_my)
{
	int x = 0;
	while(x < 1000)
	{
		my_mlx_pixel_put(mlx_my->scene, x, 10, return_white());
		x += 1;
	}
	mlx_put_image_to_window(mlx_my->mlx, mlx_my->win, mlx_my->scene, 0, 0);
}

void	draw_the_square(t_mlx_my *mlx_my)
{
	int y = 0;
	while(y < 100)
	{
		int x = 0;
		while(x < 100)
		{
			my_mlx_pixel_put(mlx_my->scene, x, y, return_white());
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(mlx_my->mlx, mlx_my->win, mlx_my->scene->img, 0, 0);
}
