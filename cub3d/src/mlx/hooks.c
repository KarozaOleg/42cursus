/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:49:41 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 15:48:05 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/hooks.h"
#include "../../include/mlx/draw.h"

t_answer	is_move_key(int keycode, t_player_move *player_move)
{
	if(keycode >= 123 && keycode <= 126)
	{
		if(keycode == 123)
			*player_move = LEFT;
		else if(keycode == 124)
			*player_move = RIGHT;
		else if(keycode == 125)
			*player_move = DOWN;
		else if(keycode == 126)
			*player_move = UP;
		
		return (SUCCESS);
	}
	return (ERROR);
}

void	player_move_handler(t_game *game, t_player_move player_move)
{
	if(player_move == LEFT)
		game->player->x -= 1;
	else if(player_move == RIGHT)
		game->player->x += 1;
	else if(player_move == DOWN)
		game->player->y += 1;
	else if(player_move == UP)
		game->player->y -= 1;	
}

int		key_pressed_handler(int keycode, t_game *game)
{
	t_player_move player_move;
	
	if(is_move_key(keycode, &player_move) == SUCCESS)
	{
		player_move_handler(game, player_move);
		draw_scene(game);
	}
	return 0;
}
void	register_mlx_hook_key_pressed(t_game *game)
{
	mlx_hook(game->mlx_my->win, 2, 1L<<0, key_pressed_handler, game);
}