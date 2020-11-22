/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:39:19 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 19:33:31 by mgaston          ###   ########.fr       */
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

void calculate_sprites(t_game *game);
void	sort_sprites(t_game *game, t_sprite **sprites);
void	draw_sprites(t_game *game, t_sprite **sprites);
void	free_sprites(t_sprite **sprites);
t_answer	return_sprites(int **map, t_sprite ***sprites);

#endif