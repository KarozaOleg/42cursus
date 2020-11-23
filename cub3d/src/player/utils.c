/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:35:39 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/23 21:18:17 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/colors.h"
#include "../../include/player/player_utils.h"

//TODO remove
#include <stdio.h>

t_bool	is_a_player(int value)
{
	if(value == MAP_PLAYER_N || value == MAP_PLAYER_S || value == MAP_PLAYER_E || value == MAP_PLAYER_W)
		return (TRUE);
	return (FALSE);
}

t_answer	init_player(t_player **player, int width)
{
	*player = malloc(sizeof(**player));
	if(*player == NULL)
		return (ERROR);
	(*player)->start_position = -1;
	(*player)->x = -1;
	(*player)->y = -1;
	(*player)->color = return_red();
	(*player)->move_speed = 4.0;
	(*player)->fov = 60.0 * (PI / 180);
	(*player)->pov = PI / 2;
	(*player)->pov_step = 2.0 * (PI / 180);
	(*player)->num_rays = width;
	return (SUCCESS);
}

t_answer	return_player_start_pov(int type, float *pov)
{
	if(type == MAP_PLAYER_N)
		*pov = PI + PI / 2;
	else if(type == MAP_PLAYER_S)
		*pov = PI / 2;
	else if(type == MAP_PLAYER_E)
		*pov = PI;
	else if(type == MAP_PLAYER_W)
		*pov = PI * 2;

	return ((*pov != 0) ? SUCCESS : ERROR);
}

t_answer	return_player(int width, int **map, int scaled_to, float minimap_ratio, t_player **player)
{
	int y;
	int x;
	
	if(init_player(player, width) == ERROR)
		return (ERROR);
	y = 0;
	while(map[y] != NULL)
	{
		x = 0;
		while(map[y][x] > -1)
		{
			if(is_a_player(map[y][x]) == TRUE)
			{
				if((*player)->start_position > -1)
					return (ERROR);
				if(return_player_start_pov(map[y][x], &((*player)->pov)) == ERROR)
					return (ERROR);
				(*player)->start_position = map[y][x];
				(*player)->x = x * (scaled_to * minimap_ratio);
				(*player)->y = y * (scaled_to * minimap_ratio);
			}
			x += 1;
		}
		y += 1;
	}
	return (SUCCESS);
}

void 		free_player(t_player *player)
{
	if(player != NULL)
		free(player);
}