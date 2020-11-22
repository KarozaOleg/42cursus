/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 17:36:28 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/draw.h"

//TODO remove
#include <stdio.h>

void	init_buffer_depth(t_game *game)
{
	float	dist;
	int		dp;
		
	dist = game->ray->index * cos(game->ray->angle - game->player->pov);
	dp = 0;
	while(dp < game->map_settings->resolution->height)
	{
		game->depth_buffer[game->ray->index][dp] = dist;
		dp += 1;
	}
}

void	return_wall_spec(t_game *game, t_wall_spec *wall_spec)
{
	float distance;
	float distance_proj_plane;
	float projected_wall_height;

	distance = game->ray->distance * cos(game->ray->angle - game->player->pov);
	distance_proj_plane = (game->map_settings->resolution->width / 2) / tan(game->player->fov / 2);
	projected_wall_height = (game->map->scaled_to / distance) * distance_proj_plane;
	
	wall_spec->wall_height = (int)projected_wall_height;
	wall_spec->wall_top = (game->map_settings->resolution->height / 2) - (wall_spec->wall_height / 2);
	wall_spec->wall_top = wall_spec->wall_top < 0 ? 0 : wall_spec->wall_top;

	wall_spec->wall_bottom = (game->map_settings->resolution->height / 2) + (wall_spec->wall_height / 2);
	wall_spec->wall_bottom = wall_spec->wall_bottom > game->map_settings->resolution->height ? game->map_settings->resolution->height : wall_spec->wall_bottom;
}

void	fill_buffer_color_ceiling(t_game *game, int x2)
{
	int x;

	x = 0;
	while(x < x2)
	{
		game->buffer_color[game->ray->index][x] = CEILING;
		x += 1;
	}
}

int		return_texture_id(t_ray *ray)
{
	int id;

	id = 0;
	if(ray->was_hit_vertical)
	{
		if((ray->angle > PI/2 && ray->angle < PI) || (ray->angle > PI && ray->angle < PI+PI/2))
			id = 1;
		else if((ray->angle > 0 && ray->angle < PI/2) || (ray->angle > PI+PI/2 && ray->angle < 2*PI))
			id = 2;
	}
	else
	{
		if(ray->angle > 0 && ray->angle < PI)
			id = 0;	
		else if(ray->angle > PI && ray->angle < 2*PI)
			id = 3;
	}
	return (id);
}

void	fill_buffer_color_wall(t_game *game, t_wall_spec *wall_spec)
{
	int y;
	int dist_from_top;
	int tex_offset_y;
	int tex_offset_x;
	int texture_id;

	texture_id = return_texture_id(game->ray);
	y = wall_spec->wall_top;
	if (game->ray->was_hit_vertical)
		tex_offset_x = ((int)game->ray->wall_hit_y % 64);
	else
		tex_offset_x = ((int)game->ray->wall_hit_x % 64);
		
	while(y < wall_spec->wall_bottom)
	{
		dist_from_top = y + (wall_spec->wall_height / 2) - (game->map_settings->resolution->height / 2);
		tex_offset_y = dist_from_top * ((float)64 / wall_spec->wall_height);
		game->buffer_color[game->ray->index][y] = return_texture_color(game->texture_wall[texture_id], tex_offset_x, tex_offset_y);
		y += 1;
	}
}

void	fill_buffer_color_floor(t_game *game, int x1)
{
	int x;

	x = x1;
	while(x < game->map_settings->resolution->height)
	{
		game->buffer_color[game->ray->index][x] = FLOOR;
		x += 1;
	}
}

void	scene_to_buffer(t_game *game)
{
	float		ray_angle;
	int			ray_index;
	t_wall_spec	wall_spec;

	ray_angle = game->player->pov - (game->player->fov / 2.0);
	ray_index = 0;
	while(ray_index < game->player->num_rays)
	{
		init_buffer_depth(game);
		init_ray(game->ray, ray_index, ray_angle);
		ray_casting(game);
		return_wall_spec(game, &wall_spec);
		fill_buffer_color_ceiling(game, wall_spec.wall_top);
		fill_buffer_color_wall(game, &wall_spec);
		fill_buffer_color_floor(game, wall_spec.wall_bottom);
		ray_angle += game->player->fov / ((float)game->player->num_rays);
		ray_index += 1;
	}
	calculate_sprites(game);
	sort_sprites(game, game->sprites, game->depth_buffer);
	draw_sprites(game, game->sprites, game->depth_buffer);
}

void	buffer_to_scene(t_game *game)
{
	int x;
	int y;
	int color;
	
	x = 0;
	while(x < game->player->num_rays)
	{
		y = 0;
		while(y < game->map_settings->resolution->height)
		{
			color = game->buffer_color[x][y];
			my_mlx_pixel_put(game->mlx_my->scene, x, y, color);
			y += 1;
		}
		x += 1;
	}
}

int		draw_scene(t_game *game)
{
	scene_to_buffer(game);
	buffer_to_scene(game);
	return (mlx_put_image_to_window(game->mlx_my->mlx, game->mlx_my->win, game->mlx_my->scene->img, 0, 0));
}
