/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 16:12:24 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/game/game_essences.h"
#include "../../include/mlx/draw.h"
#include <stdio.h>

void	draw_scaled_point(t_mlx_img *scene, int x_shifted, int y_shifted, int increase_to, int color)
{
	int y = y_shifted;
	int y_amount = 0;
	while(y_amount < increase_to)
	{
		int x = x_shifted;
		int x_amount = 0;
		while(x_amount < increase_to)
		{
			my_mlx_pixel_put(scene, x, y, color);
			x_amount += 1;
			x += 1;
		}
		y_amount += 1;
		y += 1;
	}
}

int		draw_scene(t_game *game)
{	
	draw_map(game->mlx_my->scene, game->map->array, 50);
	draw_player(game->mlx_my->scene, game->player, 50);
	return (mlx_put_image_to_window(game->mlx_my->mlx, game->mlx_my->win, game->mlx_my->scene->img, 0, 0));
}

void	draw_map(t_mlx_img *scene, int **map, int increased_to)
{		
	int y = 0;
	while(map[y] != NULL)
	{
		int x = 0;
		while(map[y][x] > -1)
		{
			if(map[y][x] == 1)
				draw_scaled_point(scene, x * increased_to, y * increased_to, increased_to, return_white());
			x += 1;
		}
		y += 1;
	}
}

void	draw_player(t_mlx_img *scene, t_player *player, int increased_to)
{
	int x = player->x * increased_to;
	int y = player->y * increased_to;
	draw_scaled_point(scene, x, y, increased_to, player->color);
}

void	draw_the_line(t_mlx_img *scene)
{
	int x = 0;
	while(x < 1000)
	{
		my_mlx_pixel_put(scene, x, 10, return_red());
		x += 1;
	}
}

void	draw_the_square(t_mlx_img *scene)
{
	int y = 0;
	while(y < 100)
	{
		int x = 0;
		while(x < 100)
		{
			my_mlx_pixel_put(scene, x, y, return_white());
			x += 1;
		}
		y += 1;
	}
}
