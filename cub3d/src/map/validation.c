/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:39:02 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 13:50:59 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/map_utils.h"

t_parse_answer	is_a_player_value(int value)
{
	t_parse_answer answer;

	answer = NOT_FOUND;
	if(value == MAP_PLAYER_N || value == MAP_PLAYER_S || value == MAP_PLAYER_E || value == MAP_PLAYER_W)
		answer = FOUND;
	return (answer);
}

t_answer is_all_integers_valid(int *arr, t_parse_answer *is_player_found)
{
	int i;

	i = 0;
	while(arr[i] != -1)
	{
		if (arr[i] != MAP_EMPTY &&
			arr[i] != MAP_WALL &&
			arr[i] != MAP_SPRITE &&
			arr[i] != MAP_UNIVERSE &&
			is_a_player_value(arr[i]) == NOT_FOUND)
			return (ERROR);
			
		if(is_a_player_value(arr[i]) == FOUND)
		{
			if(*is_player_found == FOUND)
				return (ERROR);
			*is_player_found = FOUND;
		}
		++i;
	}
	return (SUCCESS);
}

t_answer is_map_valid(int **map)
{
	t_parse_answer	is_player_found;
	int				i;

	if(map == NULL)
		return (ERROR);

	is_player_found = NOT_FOUND;
	i = 0;
	while(map[i] != NULL)
		is_all_integers_valid(map[i++], &is_player_found);
		
	if(is_player_found == NOT_FOUND)
		return (ERROR);
		
	return (SUCCESS);
}