/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:49:41 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/12 17:13:18 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/hooks.h"
#include "../../include/mlx/draw.h"

//TODO remove
#include <stdio.h>

t_answer	is_move_key(int keycode, t_player_move *player_move)
{
	if((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		if(keycode == 0)
			*player_move = LEFT;
		else if(keycode == 2)
			*player_move = RIGHT;
		else if(keycode == 1)
			*player_move = DOWN;
		else if(keycode == 13)
			*player_move = UP;
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

void	player_move_handler(t_game *game, t_player_move player_move)
{
	t_restriction *restriction;

	restriction = game->map->restrictions[game->player->y][game->player->x];
	if(player_move == LEFT)
	{
		if(restriction->left == SUCCESS)
			game->player->x -= 1;
	}
	else if(player_move == RIGHT)
	{
		if(restriction->right == SUCCESS)
			game->player->x += 1;
	}
	else if(player_move == DOWN)
	{
		if(restriction->down == SUCCESS)
			game->player->y += 1;
	}
	else if(player_move == UP)
	{
		if(restriction->up == SUCCESS)
			game->player->y -= 1;
	}
}

void	player_pov_change_handler(t_game *game, float pov_change)
{
	game->player->pov += pov_change;
}

int		key_pressed_handler(int keycode, t_game *game)
{
	t_player_move player_move;
	float pov_change;
	
	if(is_move_key(keycode, &player_move) == SUCCESS)
	{
		player_move_handler(game, player_move);
		draw_scene(game);
	}
	else if(is_pov_change_key(keycode, game->player->pov_step, &pov_change) == SUCCESS)
	{
		player_pov_change_handler(game, pov_change);
		draw_scene(game);
	}

	return 0;
}

void	register_mlx_hook_key_pressed(t_game *game)
{
	mlx_hook(game->mlx_my->win, 2, 1L<<0, key_pressed_handler, game);
}