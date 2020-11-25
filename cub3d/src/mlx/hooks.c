/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:49:41 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:21:55 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/hooks.h"
#include "../../include/mlx/draw.h"

int		close_event_handler(int keycode, t_game *game)
{
	keycode += 0;
	game += 0;
	exit(0);
	return (0);
}

int		key_pressed_handler(int keycode, t_game *game)
{
	int		player_turn;
	int		player_move;
	float	step;
	float	new_x;
	float	new_y;

	if (handle_key(keycode, &player_turn, &player_move) == SUCCESS)
	{
		game->player->pov += player_turn * game->player->pov_step;
		step = player_move * game->player->move_speed;
		new_x = game->player->x + cos(game->player->pov) * step;
		new_y = game->player->y + sin(game->player->pov) * step;
		if (game->map->array[(int)(new_y / ((float)game->map->scaled_to))][
(int)(new_x / ((float)game->map->scaled_to))] != 1)
		{
			game->player->x = new_x;
			game->player->y = new_y;
		}
	}
	else if (handle_key_close(keycode) == SUCCESS)
	{
		close_event_handler(keycode, game);
	}
	draw_scene(game);
	return (0);
}

void	register_mlx_hook_key_pressed(t_game *game)
{
	mlx_hook(game->mlx_my->win, 2, 1L, key_pressed_handler, game);
	mlx_hook(game->mlx_my->win, 17, 0L, close_event_handler, game);
}
