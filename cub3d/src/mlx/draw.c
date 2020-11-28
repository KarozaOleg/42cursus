/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 14:25:16 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/draw.h"

void	init_buffer_depth(t_game *game, int x)
{
	int		y;

	y = 0;
	while (y < game->map_settings->resolution->height)
	{
		game->buffer_depth[x][y] = game->ray->distance;
		y += 1;
	}
}

void	return_wall_spec(t_game *game, t_wall_spec *wall_spec)
{
	float distance;
	float distance_proj_plane;
	float projected_wall_height;

	distance = game->ray->distance * cos(game->ray->angle - game->player->pov);
	distance_proj_plane = (game->map_settings->resolution->width / 2) /
	tan(game->player->fov / 2);
	projected_wall_height = (game->map->scaled_to / distance) *
	distance_proj_plane;
	wall_spec->wall_height = (int)projected_wall_height;
	wall_spec->wall_top = (game->map_settings->resolution->height / 2) -
	(wall_spec->wall_height / 2);
	wall_spec->wall_top = wall_spec->wall_top < 0 ? 0 : wall_spec->wall_top;
	wall_spec->wall_bottom = (game->map_settings->resolution->height / 2) +
	(wall_spec->wall_height / 2);
	wall_spec->wall_bottom = wall_spec->wall_bottom >
	game->map_settings->resolution->height
	? game->map_settings->resolution->height : wall_spec->wall_bottom;
}

void	fill_buffer_color_ceiling(t_game *game, int x2)
{
	int x;

	x = 0;
	while (x < x2)
	{
		game->buffer_color[game->ray->index][x] =
return_int_from_trgb(0, game->map_settings->color_ceiling);
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
	while (ray_index < game->player->num_rays)
	{
		init_ray(game->ray, ray_index, ray_angle);
		ray_casting(game);
		init_buffer_depth(game, ray_index);
		return_wall_spec(game, &wall_spec);
		fill_buffer_color_ceiling(game, wall_spec.wall_top);
		fill_buffer_color_wall(game, &wall_spec);
		fill_buffer_color_floor(game, wall_spec.wall_bottom);
		ray_angle += game->player->fov / ((float)game->player->num_rays);
		ray_index += 1;
	}
	calculate_sprites(game);
	sort_sprites(game, game->sprites);
	draw_sprites(game, game->sprites);
}

int		draw_scene(t_game *game)
{
	scene_to_buffer(game);
	draw_buffer(game);
	return (mlx_put_image_to_window(game->mlx_my->mlx, game->mlx_my->win,
	game->mlx_my->scene->img, 0, 0));
}
