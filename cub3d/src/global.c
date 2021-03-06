/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:42:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 15:47:27 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game/game_utils.h"
#include "../include/global.h"

void		ft_putstr(char *str)
{
	ft_putstr_fd(str, 0);
}

int			return_x_amount(int *array)
{
	int amount;

	amount = 0;
	while (array[amount] > -1)
		amount++;
	return (amount);
}

int			return_y_amount(int **array)
{
	int amount;

	amount = 0;
	while (array[amount] != NULL)
		amount++;
	return (amount);
}

float		distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

t_answer	cub3d_exit(char *exit_comment, t_game *game)
{
	ft_putstr(exit_comment);
	if (ft_strlen(exit_comment) > 0)
		ft_putstr("\n");
	free_game(game);
	return (ERROR);
}
