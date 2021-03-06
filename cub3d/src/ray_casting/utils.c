/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:25:46 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:48:44 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray_casting/ray_casting_utils.h"

float		normalize_angle(float angle)
{
	angle = remainder(angle, PI * 2);
	if (angle < 0)
		angle = PI * 2 + angle;
	return (angle);
}

void		init_ray(t_ray *ray, int ray_index, float ray_angle)
{
	ray->index = ray_index;
	ray->angle = normalize_angle(ray_angle);
	ray->is_ray_facing_down = ray->angle > 0 && ray->angle < PI;
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = ray->angle < 0.5 * PI || ray->angle > 1.5 * PI;
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
}

void		reset_cast_result(t_ray_cast_result *cast_result)
{
	cast_result->wall_hit_x = 0;
	cast_result->wall_hit_y = 0;
	cast_result->wall_content = 0;
	cast_result->wall_hit = FALSE;
}

t_bool		map_has_wall_at(t_game *game, float x, float y)
{
	int map_grid_index_x;
	int map_grid_index_y;

	if (x < 0 || x > game->map_settings->resolution->width || y < 0
	|| y > game->map_settings->resolution->height)
		return (TRUE);
	map_grid_index_x = (int)floor(x / (float)game->map->scaled_to);
	map_grid_index_y = (int)floor(y / (float)game->map->scaled_to);
	if (game->map->array[map_grid_index_y][map_grid_index_x] == 1)
		return (TRUE);
	else
		return (FALSE);
}

float		return_intersect_dist(t_game *game, t_ray_cast_result *cast_result)
{
	float	dist;

	if (cast_result->wall_hit == TRUE)
		dist = distance_between_points(game->player->x, game->player->y,
cast_result->wall_hit_x, cast_result->wall_hit_y);
	else
		dist = 340282346638528859811704183484516925440.0;
	if (dist == 0)
		dist = 0.1;
	return (dist);
}
