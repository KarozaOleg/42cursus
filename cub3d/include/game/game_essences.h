/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_essences.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:17:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/14 18:39:45 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ESSENCES_H
# define GAME_ESSENCES_H
# include "../map/map_essences.h"
# include "../mlx/mlx_essences.h"
# include "../player/player_essences.h"
# include "../texture/texture_essence.h"
# include "../sprite/sprite_essence.h"

typedef struct	s_game
{
	t_map			*map;
	t_map_settings	*map_settings;
	t_mlx_my		*mlx_my;
	t_player		*player;
	t_sprite		**sprites;
	t_image			**texture_wall;
	t_image			*texture_sprite;
}				t_game;

typedef struct	s_ray
{
	float	distance;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_hit_content;
	t_bool	was_hit_vertical;
	float	angle;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
}				t_ray;

typedef	struct	s_ray_cast_result
{
	t_bool	wall_hit;
	float		wall_hit_x;
	float		wall_hit_y;
	int			wall_content;
}				t_ray_cast_result;
#endif