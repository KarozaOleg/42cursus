/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:25:46 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 15:32:53 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray_casting/ray_casting_utils.h"

float	normalize_angle(float angle) 
{
	angle = remainder(angle, PI * 2);
	if (angle < 0) 
		angle = PI * 2 + angle;
	return (angle);
}

void	init_ray(t_ray *ray, int ray_index, float ray_angle)
{
	ray->index = ray_index;
	ray->angle = normalize_angle(ray_angle);
	ray->is_ray_facing_down = ray->angle > 0 && ray->angle < PI;
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = ray->angle < 0.5 * PI || ray->angle > 1.5 * PI;
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
}

void	reset_cast_result(t_ray_cast_result *cast_result)
{
	cast_result->wall_hit_x = 0;
	cast_result->wall_hit_y = 0;
	cast_result->wall_content = 0;
	cast_result->wall_hit = FALSE;
}

int		return_x_amount(int *array)
{
	int amount;
	
	amount = 0;
	while(array[amount] > -1)
		amount++;
	return (amount);
}

t_bool	map_has_wall_at(t_game *game, float x, float y) 
{
	int map_grid_index_x;
	int map_grid_index_y;

	if (x < 0 || x > game->map_settings->resolution->width || y < 0 || y > game->map_settings->resolution->height)	
		return TRUE;

	map_grid_index_x = (int)floor(x / (float)game->map->scaled_to);
	map_grid_index_y = (int)floor(y / (float)game->map->scaled_to);

	if(game->map->array[map_grid_index_y][map_grid_index_x] == 1)
		return (TRUE);
	else
		return (FALSE);
}

void	casting(t_game *game, t_ray_cast_result *cast_result, int y_amount, void (*casting_spec)(t_game *, t_ray_cast_var *), void (*casting_step)(t_ray_cast_var *, t_ray *, float *,float *))
{
	t_ray_cast_var		cast_var;
	float				x2check;
	float				y2check;
	
	reset_cast_result(cast_result);
	casting_spec(game, &cast_var);
	while (1)
	{
		if((cast_var.xintercept < 0 || cast_var.xintercept > game->map_settings->resolution->width) || 
			(cast_var.yintercept < 0 || cast_var.yintercept > game->map_settings->resolution->height))
		{
			cast_result->wall_hit_x = cast_var.xintercept;
			cast_result->wall_hit_y = cast_var.yintercept;
			cast_result->wall_content = game->map->array[(int)floor(y2check / game->map->scaled_to)][(int)floor(x2check / game->map->scaled_to)];
			cast_result->wall_hit = TRUE;
			break;
		}
		casting_step(&cast_var, game->ray, &x2check, &y2check);
		if((int)floor(y2check / game->map->scaled_to) >= y_amount)
			break;
		if((int)floor(x2check / game->map->scaled_to) >= return_x_amount(game->map->array[(int)floor(y2check / game->map->scaled_to)]))
			break;
		
		if (map_has_wall_at(game, x2check, y2check) == TRUE) 
		{
			cast_result->wall_hit_x = cast_var.xintercept;
			cast_result->wall_hit_y = cast_var.yintercept;
			cast_result->wall_content = game->map->array[(int)floor(y2check / game->map->scaled_to)][(int)floor(x2check / game->map->scaled_to)];
			cast_result->wall_hit = TRUE;
			break;
		}
		else
		{
			cast_var.xintercept += cast_var.xstep;
			cast_var.yintercept += cast_var.ystep;
		}
	}
}

float	distance_between_points(float x1, float y1, float x2, float y2) 
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

float	return_intersect_dist(t_game *game, t_ray_cast_result *cast_result)
{
	float	dist;
	
	if(cast_result->wall_hit == TRUE)
		dist = distance_between_points(game->player->x, game->player->y, cast_result->wall_hit_x, cast_result->wall_hit_y);
	else
		dist = 340282346638528859811704183484516925440.0;
	if(dist == 0)
		dist = 0.1;
	return (dist);
}

void	ray_casting(t_game *game, int y_amount)
{
	t_ray_cast_result	cast_result_horz;
	float				distance_horz;
	t_ray_cast_result	cast_result_vert;
	float				distance_vert;
	
	casting(game, &cast_result_horz, y_amount, &return_casting_spec_horisontal, &return_casting_step_horisontal);
	casting(game, &cast_result_vert, y_amount, &return_casting_spec_vertical, &return_casting_step_vertical);
	
	distance_horz = return_intersect_dist(game, &cast_result_horz);
	distance_vert = return_intersect_dist(game, &cast_result_vert);
	if (distance_vert < distance_horz) 
	{
		game->ray->distance = distance_vert;
		game->ray->wall_hit_x = cast_result_vert.wall_hit_x;
		game->ray->wall_hit_y = cast_result_vert.wall_hit_y;
		game->ray->wall_hit_content = cast_result_vert.wall_content;
		game->ray->was_hit_vertical = TRUE;
	}
	else 
	{
		game->ray->distance = distance_horz;
		game->ray->wall_hit_x = cast_result_horz.wall_hit_x;
		game->ray->wall_hit_y = cast_result_horz.wall_hit_y;
		game->ray->wall_hit_content = cast_result_horz.wall_content;
		game->ray->was_hit_vertical = FALSE;
	}
}