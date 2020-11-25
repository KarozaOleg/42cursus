/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_vertical.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:23:57 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:45:53 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray_casting/ray_casting_utils.h"

void	return_casting_spec_vertical(t_game *game, t_ray_cast_var *cast_var)
{
	cast_var->xintercept = floor(game->player->x /
game->map->scaled_to) * game->map->scaled_to;
	cast_var->xintercept += game->ray->is_ray_facing_right ?
game->map->scaled_to : 0;
	cast_var->yintercept = game->player->y + (cast_var->xintercept -
game->player->x) * tan(game->ray->angle);
	cast_var->xstep = game->map->scaled_to;
	cast_var->xstep *= game->ray->is_ray_facing_left ? -1 : 1;
	cast_var->ystep = game->map->scaled_to * tan(game->ray->angle);
	cast_var->ystep *= (game->ray->is_ray_facing_up &&
cast_var->ystep > 0) ? -1 : 1;
	cast_var->ystep *= (game->ray->is_ray_facing_down &&
cast_var->ystep < 0) ? -1 : 1;
}

void	return_casting_step_vertical(t_ray_cast_var *cast_var, t_ray *ray,
float *x2check, float *y2check)
{
	*x2check = cast_var->xintercept + (ray->is_ray_facing_left ? -1 : 0);
	*y2check = cast_var->yintercept;
}
