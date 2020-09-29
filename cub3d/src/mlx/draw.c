/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/29 19:03:37 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/draw.h"
#include <math.h>

//TODO remove
#include <stdio.h>

void	draw_scaled_point(t_mlx_img *scene, int x_shifted, int y_shifted, int scaled_to, int color)
{
	int y = y_shifted;
	int y_amount = 0;
	while(y_amount < scaled_to)
	{
		int x = x_shifted;
		int x_amount = 0;
		while(x_amount < scaled_to)
		{
			my_mlx_pixel_put(scene, x, y, color);
			x_amount += 1;
			x += 1;
		}
		y_amount += 1;
		y += 1;
	}
}

void	draw_line(t_mlx_img *scene, int x1, int x2, int y1, int y2, int color)
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

void	draw_rays(int **map, t_mlx_img *scene, t_player *player, int scaled_to)
{	
	int i_ray = 0;
	float ray_angle = player->pov - (player->fov / 2.0);
	while(i_ray < player->num_rays)
	{
		float x2 = player->x;
		float y2 = player->y;
		float x2_possible = player->x;
		float y2_possible = player->y;
		while(map[(int)(y2_possible / ((float)scaled_to))][(int)(x2_possible / ((float)scaled_to))] != 1)
		{
			x2_possible += cos(ray_angle);
			y2_possible += sin(ray_angle);
			
			if(map[(int)(y2_possible / ((float)scaled_to))][(int)(x2_possible / ((float)scaled_to))] != 1)
			{				
				x2 += cos(ray_angle);
				y2 += sin(ray_angle);
			}
		}
				
		draw_line(scene, player->x, x2, player->y, y2, return_yellow());		
		i_ray += 1;
		ray_angle += player->fov / (float)player->num_rays;
	}
}

void	draw_player(t_mlx_img *scene, t_player *player)
{
	my_mlx_pixel_put(scene, player->x, player->y, player->color);
}

void	draw_map(t_mlx_img *scene, int **map, int scaled_to)
{		
	int y = 0;
	while(map[y] != NULL)
	{
		int x = 0;
		while(map[y][x] > -1)
		{
			if(map[y][x] == 1)
				// my_mlx_pixel_put(scene, x, y, return_white());
				draw_scaled_point(scene, x * scaled_to, y * scaled_to, scaled_to, return_white());
			else
				// my_mlx_pixel_put(scene, x, y, return_black());
				draw_scaled_point(scene, x * scaled_to, y * scaled_to, scaled_to, return_black());
			x += 1;
		}
		y += 1;
	}
}

int		abs(int value)
{
	if(value < 1)
		value *= -1;
	return value;
}

void	clear(t_mlx_img *scene, t_map_settings *map_settings)
{		
	int y = 0;
	while(y < map_settings->resolution->height)
	{
		int x = 0;
		while(x < map_settings->resolution->width)
		{
			my_mlx_pixel_put(scene, x, y, return_black());
			x += 1;
		}
		y += 1;
	}
}

void	draw_square(t_mlx_img *scene, int x1, int x2, int y1, int y2, int color)
{
	while(x1 < x2)
	{
		while(y1 < y2)
		{			
			my_mlx_pixel_put(scene, x1, y1, color);
			y1 += 1;
		}
		x1 += 1;
	}	
}

float	normalizeAngle(float angle) 
{
    if (angle < 0) {
        angle = (2 * PI) + angle;
    }
    return angle;
}

void	draw_projection_plane(t_game *game)
{	
	t_map *map = game->map;
	t_player *player = game->player;

	// printf("pov:%f\n",  game->player->pov);

	float ray_angle = game->player->pov - (game->player->fov / 2.0);
	int ray_index = 0;
	
	while(ray_index < game->player->num_rays)
	{
		float x_possible = (float)player->x;
		float x = (float)player->x;
		float y_possible = (float)player->y;
		float y = (float)player->y;

		while(map->array[(int)(y_possible / ((float)map->scaled_to))][(int)(x_possible / ((float)map->scaled_to))] != 1)
		{
			x_possible += cos(ray_angle) / 5;
			y_possible += sin(ray_angle) / 5;
			
			if(map->array[(int)(y_possible / ((float)map->scaled_to))][(int)(x_possible / ((float)map->scaled_to))] != 1)
			{
				x = x_possible;
				y = y_possible;
			}
		}		
		
		float ray_distance = sqrt(pow(((float)player->x) - x, 2) + pow(((float)player->y) - y, 2));

		float distance_proj_plane = ((((float)game->map_settings->resolution->width) / 2.0)) / tan(game->player->fov / 2.0);
		float wall_height = (((float)map->scaled_to) / ray_distance) * distance_proj_plane;
		
		if(wall_height > (float)game->map_settings->resolution->height)
			wall_height  = (float)game->map_settings->resolution->height;
		
		float value = (((float)game->map_settings->resolution->height) / 2.0) - (wall_height / 2.0);

		draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			0,
			value,
			CEILING);
			
		draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			value,
			value + wall_height,
			WHITE);

		draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			value + wall_height,
			game->map_settings->resolution->height,
			FLOOR);
		
		ray_angle += player->fov / ((float)player->num_rays);
		ray_index += 1;
	}
}

int		draw_scene(t_game *game)
{		

	// clear(game->mlx_my->scene, game->map_settings);

	// draw_map(game->mlx_my->scene, game->map->array, game->map->scaled_to * game->map->minimap_ratio);
	// draw_player(game->mlx_my->scene, game->player);
	// draw_rays(game->map->array, game->mlx_my->scene, game->player, game->map->scaled_to * game->map->minimap_ratio);

	draw_projection_plane(game);
	
	return (mlx_put_image_to_window(game->mlx_my->mlx, game->mlx_my->win, game->mlx_my->scene->img, 0, 0));
}
