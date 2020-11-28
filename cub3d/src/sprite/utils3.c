/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:16:29 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 14:53:53 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sprite/sprite_utils.h"

void	draw_sprites(t_game *game, t_sprite **sprites)
{
	sprites_iterate(game, sprites, game->buffer_color, draw);
}

void	free_sprites(t_sprite **sprites)
{
	int s;

	if (sprites == NULL)
		return ;
	s = 0;
	while (sprites[s] != NULL)
	{
		free(sprites[s]);
		s += 1;
	}
	free(sprites);
}
