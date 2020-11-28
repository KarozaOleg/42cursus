/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 14:25:49 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/draw.h"

int		return_texture_id(t_ray *ray)
{
	int id;

	id = 0;
	if (ray->was_hit_vertical)
	{
		if ((ray->angle > PI / 2 && ray->angle < PI) ||
(ray->angle > PI && ray->angle < PI + PI / 2))
			id = 1;
		else if ((ray->angle > 0 && ray->angle < PI / 2) ||
(ray->angle > PI + PI / 2 && ray->angle < 2 * PI))
			id = 2;
	}
	else
	{
		if (ray->angle > 0 && ray->angle < PI)
			id = 0;
		else if (ray->angle > PI && ray->angle < 2 * PI)
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
	while (y < wall_spec->wall_bottom)
	{
		dist_from_top = y + (wall_spec->wall_height / 2) -
(game->map_settings->resolution->height / 2);
		tex_offset_y = dist_from_top * ((float)64 / wall_spec->wall_height);
		game->buffer_color[game->ray->index][y] =
return_texture_color(game->texture_wall[texture_id],
tex_offset_x, tex_offset_y);
		game->buffer_depth[game->ray->index][y] = game->ray->distance;
		y += 1;
	}
}

void	fill_buffer_color_floor(t_game *game, int x1)
{
	int x;

	x = x1;
	while (x < game->map_settings->resolution->height)
	{
		game->buffer_color[game->ray->index][x] =
return_int_from_trgb(0, game->map_settings->color_floor);
		x += 1;
	}
}

void	draw_buffer(t_game *game)
{
	int x;
	int y;
	int color;

	x = 0;
	while (x < game->player->num_rays)
	{
		y = 0;
		while (y < game->map_settings->resolution->height)
		{
			color = game->buffer_color[x][y];
			my_mlx_pixel_put(game->mlx_my->scene, x, y, color);
			y += 1;
		}
		x += 1;
	}
}

int		return_int_from_trgb(int t, t_rgb *rgb)
{
	return (t << 24 | rgb->red << 16 | rgb->green << 8 | rgb->blue);
}
