/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_restrictions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:23:31 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/23 20:06:29 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/restrictions.h"

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
	while(array[amount] > -1)
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

t_answer	return_restrictions(int **array, t_restriction ****restrictions)
{
	t_restriction *restriction;
	int amount_y;
	int amount_x;
	int y;
	
	amount_y = return_amount_y(array);
	*restrictions = malloc(sizeof(**restrictions) * (1 + amount_y));
	if (*restrictions == NULL)
		return (ERROR);
	(*restrictions)[amount_y] = NULL;
	
	y = 0;
	while (array[y] != NULL)
	{
		amount_x = return_amount_x(array[y]);
		(*restrictions)[y] = malloc(sizeof(***restrictions) * (1 + amount_x));
		if((*restrictions)[y] == NULL)
			return (ERROR);
		(*restrictions)[y][amount_x] = NULL;

		int x = 0;
		while(array[y][x] > -1)
		{
			restriction = malloc(sizeof(*restriction));
			if(restriction == NULL)
				return (ERROR);
				
			if(y == 0)
				restriction->up = ERROR;
			else
				restriction->up = is_not_a_wall(array[y - 1][x]);
				
			if(x == 0)
				restriction->left = ERROR;
			else
				restriction->left = is_not_a_wall(array[y][x - 1]);

			if(y == amount_y - 1)
				restriction->down = ERROR;
			else
				restriction->down = is_not_a_wall(array[y + 1][x]);

			if(x == amount_x - 1)
				restriction->right = ERROR;
			else
				restriction->right = is_not_a_wall(array[y][x + 1]);
			
			(*restrictions)[y][x] = restriction;
			x += 1;
		}
		y += 1;
	}
	return (SUCCESS);
}