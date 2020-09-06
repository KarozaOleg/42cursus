/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_essences.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:17:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 15:51:58 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ESSENCES_H
# define GAME_ESSENCES_H
# include "../map/map_essences.h"
# include "../mlx/mlx_essences.h"
# include "../player/player_essences.h"

typedef struct	s_game
{
	t_mlx_my *mlx_my;
	t_map_settings *map_settings;
	int **map;
	t_player *player;
}				t_game;

#endif