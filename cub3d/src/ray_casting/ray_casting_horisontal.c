/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_horisontal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:23:20 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 15:26:19 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray_casting/ray_casting_utils.h"

void	return_casting_spec_horisontal(t_game *game, t_ray_cast_var *cast_var)
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

void	return_casting_step_horisontal(t_ray_cast_var *cast_var, t_ray *ray, float *x2check, float *y2check)
{
	*x2check = cast_var->xintercept;
	*y2check = cast_var->yintercept + (ray->is_ray_facing_up ? -1 : 0);
}