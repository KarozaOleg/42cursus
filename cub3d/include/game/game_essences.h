/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_essences.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:17:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 15:33:00 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ESSENCES_H
# define GAME_ESSENCES_H
# include "../map/map_essences.h"
# include "../mlx/mlx_essences.h"
# include "../player/player_essences.h"
# include "../texture/texture_essence.h"
# include "../sprite/sprite_essence.h"
# include "../ray_casting/ray_casting_essences.h"

typedef struct	s_game
{
	t_map			*map;
	t_map_settings	*map_settings;
	t_mlx_my		*mlx_my;
	t_player		*player;
	t_sprite		**sprites;
	t_image			**texture_wall;
	t_image			*texture_sprite;
	t_ray			*ray;
	float			**depth_buffer;
	int				**buffer_color;
}				t_game;

#endif