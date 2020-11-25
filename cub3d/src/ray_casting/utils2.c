/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:25:46 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 23:03:05 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray_casting/ray_casting_utils.h"

t_bool	is_continue(t_game *game, t_ray_cast_var *cast_var,
float x2check, float y2check)
{
	if (map_has_wall_at(game, x2check, y2check) == FALSE)
	{
		cast_var->xintercept += cast_var->xstep;
		cast_var->yintercept += cast_var->ystep;
		return (TRUE);
	}
	return (FALSE);
}

void	rrrrrrrr(t_game *game, t_ray_cast_result *cast_result,
t_ray_cast_var *cast_var, void (*casting_spec)(t_game *, t_ray_cast_var *))
{
	reset_cast_result(cast_result);
	casting_spec(game, cast_var);
}

void	casting(t_game *game, t_ray_cast_result *cast_result,
void (*casting_spec)(t_game *, t_ray_cast_var *),
void (*casting_step)(t_ray_cast_var *, t_ray *, float *, float *))
{
	t_ray_cast_var		cast_var;
	float				x2check;
	float				y2check;

	rrrrrrrr(game, cast_result, &cast_var, casting_spec);
	while (cast_var.xintercept >= 0 &&
cast_var.xintercept <= game->map_settings->resolution->width &&
cast_var.yintercept >= 0 &&
cast_var.yintercept <= game->map_settings->resolution->height)
	{
		casting_step(&cast_var, game->ray, &x2check, &y2check);
		if ((int)floor(y2check / game->map->scaled_to) >= game->y_amount)
			break ;
		if ((int)floor(x2check / game->map->scaled_to) >=
return_x_amount(game->map->array[(int)floor(y2check / game->map->scaled_to)]))
			break ;
		if (is_continue(game, &cast_var, x2check, y2check) == TRUE)
			continue ;
		cast_result->wall_hit_x = cast_var.xintercept;
		cast_result->wall_hit_y = cast_var.yintercept;
		cast_result->wall_content = game->map->array[(int)floor(y2check /
	game->map->scaled_to)][(int)floor(x2check / game->map->scaled_to)];
		cast_result->wall_hit = TRUE;
		break ;
	}
}

void	bye_norminette(t_game *game, float *distance_horz, float *distance_vert)
{
	casting(game, game->cast_result_horisontal,
&return_casting_spec_horisontal, &return_casting_step_horisontal);
	casting(game, game->cast_result_vertical,
&return_casting_spec_vertical, &return_casting_step_vertical);
	*distance_horz = return_intersect_dist(game, game->cast_result_horisontal);
	*distance_vert = return_intersect_dist(game, game->cast_result_vertical);
}

void	ray_casting(t_game *game)
{
	float	distance_horz;
	float	distance_vert;

	bye_norminette(game, &distance_horz, &distance_vert);
	if (distance_vert < distance_horz)
	{
		game->ray->distance = distance_vert;
		game->ray->wall_hit_x = game->cast_result_vertical->wall_hit_x;
		game->ray->wall_hit_y = game->cast_result_vertical->wall_hit_y;
		game->ray->wall_hit_content = game->cast_result_vertical->wall_content;
		game->ray->was_hit_vertical = TRUE;
	}
	else
	{
		game->ray->distance = distance_horz;
		game->ray->wall_hit_x = game->cast_result_horisontal->wall_hit_x;
		game->ray->wall_hit_y = game->cast_result_horisontal->wall_hit_y;
		game->ray->wall_hit_content =
game->cast_result_horisontal->wall_content;
		game->ray->was_hit_vertical = FALSE;
	}
}
