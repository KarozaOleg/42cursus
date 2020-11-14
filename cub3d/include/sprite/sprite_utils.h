/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:39:19 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/14 19:03:09 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_UTILS_H
# define SPRITE_UTILS_H

#include <math.h>
# include "../global.h"
# include "../global_essences.h"
#include "sprite_essence.h"
#include "../game/game_essences.h"
# include "../texture/texture_utils.h"
# include "../mlx/mlx_utils.h"

void	sort_sprites(t_game *game, float *depth_buffer);
void	draw_sprites(t_game *game, float *depth_buffer);
t_answer	return_sprites(int **map, t_sprite ***sprites);

#endif