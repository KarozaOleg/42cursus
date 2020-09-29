/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:49:41 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/29 18:29:35 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/hooks.h"
#include "../../include/mlx/draw.h"

//TODO remove
#include <stdio.h>
#include <math.h>

// t_answer	is_move_key(int keycode, int *player_move)
// {
// 	if((keycode >= 0 && keycode <= 2) || keycode == 13)
// 	{
// 		if(keycode == 0)
// 			*player_move = LEFT;
// 		else if(keycode == 2)
// 			*player_move = RIGHT;
// 		else if(keycode == 1)
// 			*player_move = BACK;
// 		else if(keycode == 13)
// 			*player_move = FRONT;
// 		else
// 			return (ERROR);
		
// 		return (SUCCESS);
// 	}
// 	return (ERROR);
// }

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

t_answer	is_pov_change_key(int keycode, float pov_step, float *pov_change)
{
	if(keycode == 123 || keycode == 124)
	{
		if(keycode == 123)
			*pov_change = pov_step;
		else if(keycode == 124)
			*pov_change = pov_step * -1;
		else
			return (ERROR);
			
		return (SUCCESS);
	}
	return (ERROR);
}

t_answer	is_pov_change_key_linux(int keycode, float pov_step, float *pov_change)
{
	if(keycode == 65361 || keycode == 65363)
	{
		if(keycode == 65361)
			*pov_change = pov_step * -1;
		else if(keycode == 65363)
			*pov_change = pov_step;
		else
			return (ERROR);
			
		return (SUCCESS);
	}
	return (ERROR);
}

// void	player_move_handler(t_game *game, t_player_move player_move)
// {
// 	if(player_move == BACK)
// 	{
// 		// x_next += -1.0 * (x_next * game->player->move_speed / 100);
// 		// y_next += -1.0 * (y_next * game->player->move_speed / 100);
// 		x_next += cos(game->player->pov) * (game->player->move_speed * -1.0);
// 		y_next += sin(game->player->pov) * (game->player->move_speed * -1.0);
// 	}
// 	else if(player_move == FRONT)
// 	{
// 		// x_next += (x_next * game->player->move_speed / 100);
// 		// y_next += (y_next * game->player->move_speed / 100);
// 		x_next += cos(game->player->pov) * (game->player->move_speed);
// 		y_next += sin(game->player->pov) * (game->player->move_speed);
// 	}
// 	if(game->map->array[(int)(y_next / ((float)game->map->scaled_to))][(int)(x_next / ((float)game->map->scaled_to))] != 1)
// 	{
// 		game->player->x = x_next;
// 		game->player->y = y_next;
// 	}
// }

	// player.rotationAngle += player.turnDirection * player.turnSpeed * deltaTime;
    // float moveStep = player.walkDirection * player.walkSpeed * deltaTime;

    // float newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
    // float newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

    // if (!mapHasWallAt(newPlayerX, newPlayerY)) {
    //     player.x = newPlayerX;
    //     player.y = newPlayerY;
    // }

int		key_pressed_handler(int keycode, t_game *game)
{
	int player_move = 0;
	int player_turn = 0;
	if(handle_key_linux(keycode, &player_turn, &player_move) == SUCCESS)
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

	// player_move_handler(game, player_move);
	draw_scene(game);
	
	return 0;
}

void	register_mlx_hook_key_pressed(t_game *game)
{
	mlx_hook(game->mlx_my->win, 2, 1L<<0, key_pressed_handler, game);
	// mlx_hook(game->mlx_my->win, 3, 1L<<1, key_pressed_handler, game);
}