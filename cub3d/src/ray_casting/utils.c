/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:25:46 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 14:37:47 by mgaston          ###   ########.fr       */
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

void	return_cast_horisontal_spec(t_game *game, t_ray_cast_var *cast_var)
{
	cast_var->yintercept = floor(game->player->y / game->map->scaled_to) * game->map->scaled_to;
    cast_var->yintercept += game->ray->is_ray_facing_down ? game->map->scaled_to : 0;

    cast_var->xintercept = game->player->x + (cast_var->yintercept - game->player->y) / tan(game->ray->angle);

    cast_var->ystep = game->map->scaled_to;
    cast_var->ystep *= game->ray->is_ray_facing_up ? -1 : 1;

    cast_var->xstep = game->map->scaled_to / tan(game->ray->angle);
    cast_var->xstep *= (game->ray->is_ray_facing_left && cast_var->xstep > 0) ? -1 : 1;
    cast_var->xstep *= (game->ray->is_ray_facing_right && cast_var->xstep < 0) ? -1 : 1;
}

void	return_cast_vertical_spec(t_game *game, t_ray_cast_var *cast_var)
{
	cast_var->xintercept = floor(game->player->x / game->map->scaled_to) * game->map->scaled_to;
    cast_var->xintercept += game->ray->is_ray_facing_right ? game->map->scaled_to : 0;

    cast_var->yintercept = game->player->y + (cast_var->xintercept - game->player->x) * tan(game->ray->angle);

    cast_var->xstep = game->map->scaled_to;
    cast_var->xstep *= game->ray->is_ray_facing_left ? -1 : 1;

    cast_var->ystep = game->map->scaled_to * tan(game->ray->angle);
    cast_var->ystep *= (game->ray->is_ray_facing_up && cast_var->ystep > 0) ? -1 : 1;
    cast_var->ystep *= (game->ray->is_ray_facing_down && cast_var->ystep < 0) ? -1 : 1;
}

int return_x_amount(int *array)
{
	int amount;
	
	amount = 0;
	while(array[amount] > -1)
		amount++;
	return (amount);
}

t_bool map_has_wall_at(t_game *game, float x, float y) 
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

void	ray_cast_horisontal(t_game *game, t_ray *ray, int y_amount)
{	
	t_ray_cast_var cast_var;
	t_ray_cast_result *cast_result;
	float xToCheck;
	float yToCheck;
	
	cast_result = game->cast_result_horisontal;
	reset_cast_result(cast_result);
	return_cast_horisontal_spec(game, &cast_var);

	while (1)
	{
		if((cast_var.xintercept < 0 || cast_var.xintercept > game->map_settings->resolution->width) || (cast_var.yintercept < 0 || cast_var.yintercept > game->map_settings->resolution->height))
		{
			cast_result->wall_hit_x = cast_var.xintercept;
			cast_result->wall_hit_y = cast_var.yintercept;
			cast_result->wall_content = game->map->array[(int)floor(yToCheck / game->map->scaled_to)][(int)floor(xToCheck / game->map->scaled_to)];
			cast_result->wall_hit = TRUE;
			break;
		}

		xToCheck = cast_var.xintercept;
    	yToCheck = cast_var.yintercept + (ray->is_ray_facing_up ? -1 : 0);
			
		if((int)floor(yToCheck / game->map->scaled_to) >= y_amount)
			break;
		if((int)floor(xToCheck / game->map->scaled_to) >= return_x_amount(game->map->array[(int)floor(yToCheck / game->map->scaled_to)]))
			break;
		
        if (map_has_wall_at(game, xToCheck, yToCheck) == TRUE) 
		{
			cast_result->wall_hit_x = cast_var.xintercept;
			cast_result->wall_hit_y = cast_var.yintercept;
			cast_result->wall_content = game->map->array[(int)floor(yToCheck / game->map->scaled_to)][(int)floor(xToCheck / game->map->scaled_to)];
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

void	ray_cast_vertical(t_game *game, t_ray *ray, int y_amount)
{	
	t_ray_cast_var cast_var;
	t_ray_cast_result *cast_result;
	float xToCheck;
	float yToCheck;

	cast_result = game->cast_result_vertical;
	reset_cast_result(cast_result);
	return_cast_vertical_spec(game, &cast_var);

    while (cast_var.xintercept >= 0 && cast_var.xintercept <= game->map_settings->resolution->width && cast_var.yintercept >= 0 && cast_var.yintercept <= game->map_settings->resolution->height) 
	{
        xToCheck = cast_var.xintercept + (ray->is_ray_facing_left ? -1 : 0);
        yToCheck = cast_var.yintercept;

		if((int)floor(yToCheck / game->map->scaled_to) >= y_amount)
			break;
		if((int)floor(xToCheck / game->map->scaled_to) >= return_x_amount(game->map->array[(int)floor(yToCheck / game->map->scaled_to)]))
			break;

        if (map_has_wall_at(game, xToCheck, yToCheck) == TRUE) 
		{
			cast_result->wall_hit_x = cast_var.xintercept;
			cast_result->wall_hit_y = cast_var.yintercept;
			cast_result->wall_content = game->map->array[(int)floor(yToCheck / game->map->scaled_to)][(int)floor(xToCheck / game->map->scaled_to)];
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

void	cast_ray(t_game *game, int y_amount)
{
	float horz_distance;
	float vert_distance;
	ray_cast_horisontal(game, game->ray, y_amount);
	ray_cast_vertical(game, game->ray, y_amount);
	
	if(game->cast_result_horisontal->wall_hit == TRUE)
		horz_distance = distance_between_points(game->player->x, game->player->y, game->cast_result_horisontal->wall_hit_x, game->cast_result_horisontal->wall_hit_y);	
	else
		horz_distance = 340282346638528859811704183484516925440.0;	

	if(game->cast_result_vertical->wall_hit == TRUE)
		vert_distance = distance_between_points(game->player->x, game->player->y, game->cast_result_vertical->wall_hit_x, game->cast_result_vertical->wall_hit_y);	
	else
		vert_distance = 340282346638528859811704183484516925440.0;
		
	if (vert_distance < horz_distance) 
	{
		if(vert_distance == 0)
			vert_distance = 0.1;
		game->ray->distance = vert_distance;
		game->ray->wall_hit_x = game->cast_result_vertical->wall_hit_x;
		game->ray->wall_hit_y = game->cast_result_vertical->wall_hit_y;
		game->ray->wall_hit_content = game->cast_result_vertical->wall_content;
		game->ray->was_hit_vertical = TRUE;
	}
	else 
	{
		if(horz_distance == 0)
			horz_distance = 0.1;
		game->ray->distance = horz_distance;
		game->ray->wall_hit_x = game->cast_result_horisontal->wall_hit_x;
		game->ray->wall_hit_y = game->cast_result_horisontal->wall_hit_y;
		game->ray->wall_hit_content = game->cast_result_horisontal->wall_content;
		game->ray->was_hit_vertical = FALSE;
	}
}