/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:39:02 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:10:11 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/map_utils.h"

t_bool		is_closed_from_up(int **array, int y, int x)
{
	int i;

	i = x;
	while (i >= 0)
	{
		if (array[y][i] == 1)
			return (TRUE);
		i -= 1;
	}
	return (FALSE);
}

t_bool		is_closed_from_left(int **array, int y, int x)
{
	int i;

	i = y;
	while (i >= 0)
	{
		if (array[i][x] == 1)
			return (TRUE);
		i -= 1;
	}
	return (FALSE);
}

t_bool		is_closed_from_right(int **array, int y, int x)
{
	int i;
	int x_total;

	x_total = return_x_amount(array[y]);
	i = x;
	while (i < x_total)
	{
		if (array[y][i] == 1)
			return (TRUE);
		i += 1;
	}
	return (FALSE);
}

t_bool		is_closed_from_down(int **array, int y, int x)
{
	int i;
	int y_total;

	y_total = return_y_amount(array);
	i = y;
	while (i < y_total)
	{
		if (array[i][x] == 1)
			return (TRUE);
		i += 1;
	}
	return (FALSE);
}

t_answer	is_map_closed(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (map->array[y] != NULL)
	{
		x = 0;
		while (map->array[y][x] != -1)
		{
			if (map->array[y][x] != 1)
			{
				if (is_closed_from_left(map->array, y, x) == FALSE)
					return (ERROR);
				if (is_closed_from_up(map->array, y, x) == FALSE)
					return (ERROR);
				if (is_closed_from_right(map->array, y, x) == FALSE)
					return (ERROR);
				if (is_closed_from_down(map->array, y, x) == FALSE)
					return (ERROR);
			}
			x += 1;
		}
		y += 1;
	}
	return (SUCCESS);
}
