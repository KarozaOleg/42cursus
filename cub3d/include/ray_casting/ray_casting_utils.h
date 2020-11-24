/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:26:49 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/24 20:38:44 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_UTILS_H
# define RAY_CASTING_UTILS_H

# include "../global.h"
# include "ray_casting_essences.h"
# include <math.h>

void	init_ray(t_ray *ray, int ray_index, float ray_angle);
void	ray_casting(t_game *game);
void	return_casting_spec_vertical(t_game *game, t_ray_cast_var *cast_var);
void	return_casting_step_vertical(t_ray_cast_var *cast_var, t_ray *ray, float *x2check, float *y2check);
void	return_casting_spec_horisontal(t_game *game, t_ray_cast_var *cast_var);
void	return_casting_step_horisontal(t_ray_cast_var *cast_var, t_ray *ray, float *x2check, float *y2check);

#endif