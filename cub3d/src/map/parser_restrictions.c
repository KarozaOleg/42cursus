/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_restrictions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:23:31 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 16:56:02 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/restrictions.h"

//TODO remove
#include <stdio.h>

t_answer	is_not_a_wall(int value)
{
	if(value == 0 || value == 2 || value == 4 || value == 5 || value == 6 || value == 7)
		return (SUCCESS);
	return (ERROR);
}

int			return_amount_x(int *array)
{
	int amount;

	amount = 0;
	while(array[amount] > - 1)
		amount += 1;
	return (amount);
}

int			return_amount_y(int **array)
{
	int amount;

	amount = 0;
	while (array[amount] != NULL)
		amount += 1;
	return (amount);
}

t_answer	return_restrictions_x(int **map, t_restriction ***restrictions)
{
	int y;

	*restrictions = malloc(sizeof(**restrictions) * (1 + return_amount_y(map)));
	if (*restrictions == NULL)
		return (ERROR);
	(*restrictions)[return_amount_y(map)] = NULL;
	
	y = 0;
	while (map[y] != NULL)
	{
		(*restrictions)[y] = malloc(sizeof(***restrictions));
		if((*restrictions)[y] == NULL)
			return (ERROR);

		int x_min = -1;
		int x_max = -1;
		int x = 0;
		while(map[y][x] > -1)
		{
			printf("x:%d, y:%d\n", x, y);
			if(is_not_a_wall(map[y][x]) == SUCCESS)
			{
				printf("not a wall\n");
				
				if(x_min == -1)
					x_min = x;
				if(x_max < x)
					x_max = x;
			}
			x += 1;
		}
		(*restrictions)[y]->min = x_min;
		(*restrictions)[y]->max = x_max;
		y += 1;
	}
	return (SUCCESS);
}