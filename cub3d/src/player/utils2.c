/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:35:39 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:43:46 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/colors.h"
#include "../../include/player/player_utils.h"

t_answer		hi_norminette(t_game *game, t_player **player, int y, int x)
{
	if ((*player)->start_position > -1)
		return (ERROR);
	if (return_player_start_pov(game->map->array[y][x],
&((*player)->pov)) == ERROR)
		return (ERROR);
	(*player)->start_position = game->map->array[y][x];
	(*player)->x = x * (game->map->scaled_to * game->map->minimap_ratio);
	(*player)->y = y * (game->map->scaled_to * game->map->minimap_ratio);
	return (SUCCESS);
}

t_answer		return_player(t_game *game, t_player **player)
{
	int y;
	int x;

	if (init_player(player, game->map_settings->resolution->width) == ERROR)
		return (ERROR);
	y = 0;
	while (game->map->array[y] != NULL)
	{
		x = 0;
		while (game->map->array[y][x] > -1)
		{
			if (is_a_player(game->map->array[y][x]) == TRUE)
				if (hi_norminette(game, player, y, x) == ERROR)
					return (ERROR);
			x += 1;
		}
		y += 1;
	}
	return (SUCCESS);
}
