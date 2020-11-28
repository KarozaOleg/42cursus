/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:15:40 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 16:36:01 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/map_utils.h"

t_parse_answer		is_a_map_item(int value)
{
	int converted;

	return (return_char2int_for_map(value, &converted));
}

t_parse_answer		return_char2int_for_map(int value, int *converted)
{
	*converted = -1;
	if (value == 48)
		*converted = MAP_EMPTY;
	if (value == 49)
		*converted = MAP_WALL;
	if (value == 50)
		*converted = MAP_SPRITE;
	if (value == 32)
		*converted = MAP_UNIVERSE;
	if (value == 78)
		*converted = MAP_PLAYER_N;
	if (value == 83)
		*converted = MAP_PLAYER_S;
	if (value == 69)
		*converted = MAP_PLAYER_E;
	if (value == 87)
		*converted = MAP_PLAYER_W;
	return ((*converted > -1) ? FOUND : NOT_FOUND);
}

t_answer			is_a_map_line(char *line)
{
	int	i;

	if (line == NULL)
		return (ERROR);
	i = 0;
	while (line[i] != '\0')
	{
		if (is_a_map_item(line[i]) == NOT_FOUND)
			return (ERROR);
		++i;
	}
	return ((i == 0) ? ERROR : SUCCESS);
}

void				free_map(t_map *map)
{
	int i;

	if (map == NULL)
		return ;
	if (map->array != NULL)
	{
		i = 0;
		while (map->array[i] != NULL)
			free(map->array[i++]);
		free(map->array);
	}
	free(map);
}
