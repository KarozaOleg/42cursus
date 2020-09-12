/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/12 17:55:40 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/draw.h"
#include <math.h>

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

void draw_line(t_mlx_img *scene, int x1, int x2, int y1, int y2, int color)
{
	int x;
	int y;
	int dx;
	int dy;
	int dx1;
	int dy1;
	int px;
	int py;
	int xe;
	int ye;
	int i;
 	dx=x2-x1;
	dy=y2-y1;
	dx1=abs(dx);
	dy1=abs(dy);
	px=2*dy1-dx1;
	py=2*dx1-dy1;
	if(dy1<=dx1)
	{
		if(dx>=0)
		{
			x=x1;
			y=y1;
			xe=x2;
		}
		else
		{
			x=x2;
			y=y2;
			xe=x1;
		}

		my_mlx_pixel_put(scene, x, y, color);
		for(i=0;x<xe;i++)
		{
			x=x+1;
			if(px<0)
			{
				px=px+2*dy1;
			}
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
				{
					y=y+1;
				}
				else
				{
					y=y-1;
				}
				px=px+2*(dy1-dx1);
			}
			my_mlx_pixel_put(scene, x, y, color);
		}
	}
	else
	{
		if(dy>=0)
		{
			x=x1;
			y=y1;
			ye=y2;
		}
		else
		{
			x=x2;
			y=y2;
			ye=y1;
		}		
		my_mlx_pixel_put(scene, x, y, color);
		for(i=0;y<ye;i++)
		{
			y=y+1;
			if(py<=0)
			{
				py=py+2*dx1;
			}
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
				{
					x=x+1;
				}
				else
				{
					x=x-1;
				}
				py=py+2*(dx1-dy1);
			}
			my_mlx_pixel_put(scene, x, y, color);
		}
	}
}

void	draw_rays(t_mlx_img *scene, t_player *player, int increased_to)
{
	float ray_angle = player->pov - (player->fov / 2);
	int i_ray = 0;
	while(i_ray < player->num_rays)
	{
		int x1 = player->x * increased_to + increased_to / 2;
		int x2 = x1 + cos(ray_angle) * 150;
		int y1 = player->y * increased_to + increased_to / 2;
		int y2 = y1 + sin(ray_angle) * 150;
		draw_line(scene, x1, x2, y1, y2, return_yellow());
		
		ray_angle += player->fov / player->num_rays;
		i_ray += 1;
	}
}

void	draw_player(t_mlx_img *scene, t_player *player, int increased_to)
{
	int x = player->x * increased_to;
	int y = player->y * increased_to;
	draw_scaled_point(scene, x, y, increased_to, player->color);
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
			else
				draw_scaled_point(scene, x * increased_to, y * increased_to, increased_to, return_black());
			x += 1;
		}
		y += 1;
	}
}

int abs(int value)
{
	if(value < 1)
		value *= -1;
	return value;
}


void	clear(t_mlx_img *scene, int **map, int increased_to)
{		
	int y = 0;
	while(map[y] != NULL)
	{
		int x = 0;
		while(map[y][x] > -1)
		{
				draw_scaled_point(scene, x * increased_to, y * increased_to, increased_to, return_black());
			x += 1;
		}
		y += 1;
	}
}

int		draw_scene(t_game *game)
{	
	// clear(game->mlx_my->scene, game->map->array, 50);
	draw_map(game->mlx_my->scene, game->map->array, 50);
	// draw_player(game->mlx_my->scene, game->player, 50);
	draw_rays(game->mlx_my->scene, game->player, 50);
	return (mlx_put_image_to_window(game->mlx_my->mlx, game->mlx_my->win, game->mlx_my->scene->img, 0, 0));
}
