/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:13:54 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:01:51 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/game/game_utils.h"

void		free_game2(t_game *game)
{
	int i;

	i = 0;
	if (game->buffer_depth != NULL)
	{
		while (game->buffer_depth[i] != NULL)
			free(game->buffer_depth[i++]);
		free(game->buffer_depth);
	}
	i = 0;
	if (game->buffer_color != NULL)
	{
		while (game->buffer_color[i] != NULL)
			free(game->buffer_color[i++]);
		free(game->buffer_color);
	}
	free(game);
}

void		free_game(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->ray != NULL)
		free(game->ray);
	free_map(game->map);
	if (game->cast_result_horisontal != NULL)
		free(game->cast_result_horisontal);
	if (game->cast_result_vertical != NULL)
		free(game->cast_result_vertical);
	free_map_settings(game->map_settings);
	free_mlx(game->mlx_my);
	free_player(game->player);
	free_sprites(game->sprites);
	free_texture_sprite(game->texture_sprite);
	free_texture_walls(game->texture_wall);
	free_game2(game);
}
