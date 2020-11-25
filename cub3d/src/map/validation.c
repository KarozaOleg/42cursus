/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:39:02 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/24 21:36:57 by mgaston          ###   ########.fr       */
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

t_answer is_map_valid(t_map *map)
{
	t_parse_answer	is_player_found;
	int				i;

	if(map->array == NULL)
		return (ERROR);

	is_player_found = NOT_FOUND;
	i = 0;
	while(map->array[i] != NULL)
		is_all_integers_valid(map->array[i++], &is_player_found);
		
	if(is_player_found == NOT_FOUND)
		return (ERROR);
		
	return (SUCCESS);
}

t_bool is_closed_from_up(int **array, int y, int x)
{
	int i;

	i = x;
	while(i >= 0)
	{
		if(array[y][i] == 1)
			return (TRUE);
		i -= 1;
	}
	return (FALSE);
}

t_bool is_closed_from_left(int **array, int y, int x)
{
	int i;

	i = y;
	while(i >= 0)
	{
		if(array[i][x] == 1)
			return (TRUE);
		i -= 1;
	}
	return (FALSE);
}

t_bool is_closed_from_right(int **array, int y, int x)
{
	int i;
	int x_total;

	x_total = return_x_amount(array[y]);
	i = x;
	while(i < x_total)
	{
		if(array[y][i] == 1)
			return (TRUE);
		i += 1;
	}
	return (FALSE);
}

t_bool is_closed_from_down(int **array, int y, int x)
{
	int i;
	int y_total;

	y_total = return_y_amount(array);
	i = y;
	while(i < y_total)
	{
		if(array[i][x] == 1)
			return (TRUE);
		i += 1;
	}
	return (FALSE);
}

t_answer is_map_closed(t_map *map)
{
	int y;
	int x;

	y = 0;
	while(map->array[y] != NULL)
	{
		x = 0;
		while(map->array[y][x] != -1)
		{
			if(map->array[y][x] == 1)
			{
				x += 1;
				continue;
			}
			if(is_closed_from_left(map->array, y, x) == FALSE)
				return (ERROR);
			if(is_closed_from_up(map->array, y, x) == FALSE)
				return (ERROR);
			if(is_closed_from_right(map->array, y, x) == FALSE)
				return (ERROR);
			if(is_closed_from_down(map->array, y, x) == FALSE)
				return (ERROR);
			x += 1;
		}
		y += 1;
	}
	return (SUCCESS);
}