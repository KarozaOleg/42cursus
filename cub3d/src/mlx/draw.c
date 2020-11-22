/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 14:22:15 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/draw.h"
#include <math.h>

//TODO remove
#include <stdio.h>

typedef struct	s_ray_cast_var
{
	float xstep;
	float ystep;
	float xintercept;
	float yintercept;
}				t_ray_cast_var;

void	init_buffer_depth(t_game *game)
{
	float dist;
	int dp;
		
	dist = game->ray->index * cos(game->ray->angle - game->player->pov);
	dp = 0;
	while(dp < game->map_settings->resolution->height)
	{
		game->depth_buffer[game->ray->index][dp] = dist;
		dp += 1;
	}
}

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

int return_x_amount(int *array)
{
	int amount;
	
	amount = 0;
	while(array[amount] > -1)
		amount++;
	return (amount);
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

void	return_wall_spec(t_game *game, int *wall_top, int *wall_bottom, int *wall_height)
{
	float distance;
	float distance_proj_plane;
	float projected_wall_height;

	distance = game->ray->distance * cos(game->ray->angle - game->player->pov);
	distance_proj_plane = (game->map_settings->resolution->width / 2) / tan(game->player->fov / 2);
	projected_wall_height = (game->map->scaled_to / distance) * distance_proj_plane;
	
	*wall_height = (int)projected_wall_height;
	*wall_top = (game->map_settings->resolution->height / 2) - (*wall_height / 2);
	*wall_top = *wall_top < 0 ? 0 : *wall_top;

	*wall_bottom = (game->map_settings->resolution->height / 2) + (*wall_height / 2);
	*wall_bottom = *wall_bottom > game->map_settings->resolution->height ? game->map_settings->resolution->height : *wall_bottom;
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

void	fill_buffer_color_wall(t_game *game, int wall_top, int wall_bottom, int wall_height)
{
	int y;
	int dist_from_top;
	int tex_offset_y;
	int tex_offset_x;

	y = wall_top;
	while(y < wall_bottom)
	{
		dist_from_top = y + (wall_height / 2) - (game->map_settings->resolution->height / 2);
		tex_offset_y = dist_from_top * ((float)64 / wall_height);
		if (game->ray->was_hit_vertical)
			tex_offset_x = ((int)game->ray->wall_hit_y % 64);
		else
			tex_offset_x = ((int)game->ray->wall_hit_x % 64);
		game->buffer_color[game->ray->index][y] = return_texture_color(game->texture_wall[return_texture_id(game->ray)], tex_offset_x, tex_offset_y);
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

int		return_y_amount(int **array)
{
	int amount;
	
	amount = 0;
	while(array[amount] != NULL)
		amount++;
	return (amount);
}

void	draw_projection_plane_to_buffer(t_game *game)
{
	float ray_angle;
	int ray_index;
	int wall_top;
	int wall_bottom;
	int wall_height;
	int y_amount;

	y_amount = return_y_amount(game->map->array);
	ray_angle = game->player->pov - (game->player->fov / 2.0);
	ray_index = 0;
	while(ray_index < game->player->num_rays)
	{
		init_buffer_depth(game);
		init_ray(game->ray, ray_index, ray_angle);
		cast_ray(game, y_amount);
		return_wall_spec(game, &wall_top, &wall_bottom, &wall_height);
		fill_buffer_color_ceiling(game, wall_top);
		fill_buffer_color_wall(game, wall_top, wall_bottom, wall_height);
		fill_buffer_color_floor(game, wall_bottom);
		ray_angle += game->player->fov / ((float)game->player->num_rays);
		ray_index += 1;
	}
	calculate_sprites(game);
	sort_sprites(game, game->depth_buffer);
	draw_sprites(game, game->depth_buffer);
}

void	draw_buffer_to_scene(t_game *game)
{
	int x;
	int y;
	
	x = 0;
	while(x < game->player->num_rays)
	{
		y = 0;
		while(y < game->map_settings->resolution->height)
		{
			int color = game->buffer_color[x][y];
			my_mlx_pixel_put(game->mlx_my->scene, x, y, color);
			y += 1;
		}
		x += 1;
	}
}

int		draw_scene(t_game *game)
{
	draw_projection_plane_to_buffer(game);
	draw_buffer_to_scene(game);
		
	return (mlx_put_image_to_window(game->mlx_my->mlx, game->mlx_my->win, game->mlx_my->scene->img, 0, 0));
}
