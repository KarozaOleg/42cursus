/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:26:49 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 14:38:06 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_UTILS_H
# define RAY_CASTING_UTILS_H

# include "../global.h"
# include "ray_casting_essences.h"
#include <math.h>

void	init_ray(t_ray *ray, int ray_index, float ray_angle);
void	cast_ray(t_game *game, int y_amount);

#endif