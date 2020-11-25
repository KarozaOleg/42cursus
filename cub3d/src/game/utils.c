/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:13:54 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 21:56:06 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/game/game_utils.h"

t_answer	create_game(t_game **game)
{
	*game = malloc(sizeof(**game));
	if (*game == NULL)
		return (ERROR);
	return (SUCCESS);
}

t_answer	return_ray(t_ray **ray)
{
	*ray = malloc(sizeof(**ray));
	if (*ray == NULL)
		return (ERROR);
	return (SUCCESS);
}

t_answer	return_depth_buffer(int rays_amount, int height,
float ***depth_buffer)
{
	int i;

	(*depth_buffer) = malloc(sizeof(*depth_buffer) * (1 + rays_amount));
	if ((*depth_buffer) == NULL)
		return (ERROR);
	(*depth_buffer)[rays_amount] = NULL;
	i = 0;
	while (i < rays_amount)
	{
		(*depth_buffer)[i] = malloc(sizeof(***depth_buffer) * height);
		if ((*depth_buffer)[i] == NULL)
			return (ERROR);
		i += 1;
	}
	return (SUCCESS);
}

t_answer	return_buffer_color(int rays_amount, int height,
float ***buffer_color)
{
	int i;

	(*buffer_color) = malloc(sizeof(*buffer_color) * (1 + rays_amount));
	if ((*buffer_color) == NULL)
		return (ERROR);
	(*buffer_color)[rays_amount] = NULL;
	i = 0;
	while (i < rays_amount)
	{
		(*buffer_color)[i] = malloc(sizeof(***buffer_color) * height);
		if ((*buffer_color)[i] == NULL)
			return (ERROR);
		i += 1;
	}
	return (SUCCESS);
}

t_answer	return_cast_result_h(t_ray_cast_result **cast_result_h)
{
	*cast_result_h = malloc(sizeof(**cast_result_h));
	if (*cast_result_h == NULL)
		return (ERROR);
	return (SUCCESS);
}
