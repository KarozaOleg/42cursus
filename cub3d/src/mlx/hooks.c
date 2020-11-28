/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:49:41 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 22:49:16 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/hooks.h"

void	return_step(t_game *game, t_player_move *player_move, float *step)
{
	if (*player_move == LEFT || *player_move == BACK)
		*step = -1 * game->player->move_speed;
	else if (*player_move == RIGHT || *player_move == FRONT)
		*step = 1 * game->player->move_speed;
}

void	handle_move(t_game *game, float new_x, float new_y)
{
	if (game->map->array[(int)(new_y / ((float)game->map->scaled_to))]
[(int)(new_x / ((float)game->map->scaled_to))] != 1)
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	handle_player_move(t_game *game, t_player_move *player_move)
{
	float	step;
	float	new_x;
	float	new_y;

	new_x = 0;
	new_y = 0;
	step = 0;
	if (player_move == UNDEFINED)
		return ;
	return_step(game, player_move, &step);
	if (*player_move == LEFT || *player_move == RIGHT)
	{
		new_x = game->player->x + cos(game->player->pov + 1.5708) * step;
		new_y = game->player->y + sin(game->player->pov + 1.5708) * step;
	}
	else if (*player_move == FRONT || *player_move == BACK)
	{
		new_x = game->player->x + cos(game->player->pov) * step;
		new_y = game->player->y + sin(game->player->pov) * step;
	}
	handle_move(game, new_x, new_y);
}

int		key_pressed_handler(int keycode, t_game *game)
{
	int				pov_change;
	t_player_move	player_move;

	if (handle_key(keycode, &pov_change, &player_move) == SUCCESS)
	{
		game->player->pov += pov_change * game->player->pov_step;
		handle_player_move(game, &player_move);
	}
	else if (handle_key_close(keycode) == SUCCESS)
		close_event_handler(keycode, game);
	draw_scene(game);
	return (0);
}

void	register_mlx_hook_key_pressed(t_game *game)
{
	mlx_hook(game->mlx_my->win, 2, 1L, key_pressed_handler, game);
	mlx_hook(game->mlx_my->win, 17, 0L, close_event_handler, game);
}
