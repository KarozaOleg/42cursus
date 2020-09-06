/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:35:39 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 13:49:05 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/colors.h"
#include "../../include/player/player_utils.h"

t_answer	is_a_player(int value)
{
	if(value == MAP_PLAYER_N || value == MAP_PLAYER_S || value == MAP_PLAYER_E || value == MAP_PLAYER_W)
		return (SUCCESS);
	return (ERROR);
}

t_answer	return_player(int **map, t_player **player)
{
	*player = malloc(sizeof(*player));
	if(*player == NULL)
		return (ERROR);

	(*player)->start_position = -1;
	(*player)->x = -1;
	(*player)->y = -1;
	(*player)->color = return_red();

	int y = 0;
	while(map[y] != NULL)
	{
		int x = 0;
		while(map[y][x] > -1)
		{			
			if(is_a_player(map[y][x]) == SUCCESS)
			{
				(*player)->start_position = map[y][x];
				(*player)->x = x;
				(*player)->y = y;
				break;
			}
			x += 1;
		}
		if((*player)->start_position > -1)
				break;
		y += 1;
	}
	return (SUCCESS);
}

void 		free_player(t_player *player)
{
	if(player != NULL)
		free(player);
}