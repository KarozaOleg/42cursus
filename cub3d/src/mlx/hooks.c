/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:49:41 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/15 15:14:44 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/hooks.h"
#include "../../include/mlx/draw.h"

//TODO remove
#include <stdio.h>
#include <math.h>

t_answer	handle_key_linux(int keycode, int *pov_change, int *player_move)
{
	if(keycode == 97 || keycode == 119 || keycode == 100 || keycode == 115)
	{
		if(keycode == 97)
		 	*pov_change = -1;
		else if(keycode == 100)
			*pov_change = 1;
		else if(keycode == 115)
			*player_move = -1;
		else if(keycode == 119)
			*player_move = 1;
		else
			return (ERROR);
		return (SUCCESS);
	}
	return (ERROR);
}

t_answer	handle_key_macos(int keycode, int *pov_change, int *player_move)
{
	*pov_change = 0;
	*player_move = 0;
	if((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		if(keycode == 0)
		 	*pov_change = -1;
		else if(keycode == 2)
			*pov_change = 1;
		else if(keycode == 1)
			*player_move = -1;
		else if(keycode == 13)
			*player_move = 1;
		else
			return (ERROR);
		return (SUCCESS);
	}
	return (ERROR);
}

t_answer	handle_key_close(int keycode)
{
	if(keycode != 53)
		return ERROR;
	return SUCCESS;
}

int close_event_handler(int keycode, t_game *game)
{
	keycode += 0;
	game += 0;
	exit(0);
	return (0);
}

int		key_pressed_handler(int keycode, t_game *game)
{
	int player_turn;
	int player_move;
	
	if(handle_key_macos(keycode, &player_turn, &player_move) == SUCCESS)
	{
		game->player->pov += player_turn * game->player->pov_step;

		float step = player_move * game->player->move_speed;
		float newX = game->player->x + cos(game->player->pov) * step;
		float newY = game->player->y + sin(game->player->pov) * step;

		if(game->map->array[(int)(newY / ((float)game->map->scaled_to))][(int)(newX / ((float)game->map->scaled_to))] != 1)
		{
			game->player->x = newX;
			game->player->y = newY;
		}
	}
	else if(handle_key_close(keycode) == SUCCESS)
	{		
		close_event_handler(keycode, game);
	}
	draw_scene(game);
	return 0;
}

void	register_mlx_hook_key_pressed(t_game *game)
{
	mlx_hook(game->mlx_my->win, 2, 1L, key_pressed_handler, game);
	mlx_hook(game->mlx_my->win, 17, 0L, close_event_handler, game);
}