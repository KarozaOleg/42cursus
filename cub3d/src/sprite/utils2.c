/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:16:29 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 14:53:17 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sprite/sprite_utils.h"

float		sort(t_game *game, t_sprite *sprite, int x, int y)
{
	x += 0;
	y += 0;
	return (sprite->sprite_dist * game->map->scaled_to);
}

float		draw(t_game *game, t_sprite *sprite, int x, int y)
{
	return (return_texture_color_sprite(game->texture_sprite,
	sprite->sprite_screen_size, x, y));
}

void		sprite_iterate_part(t_game *game, t_sprite *sprite, float **buffer,
float (*action)(t_game *, t_sprite *, int, int))
{
	int x;
	int y;

	x = -1;
	while (++x < sprite->sprite_screen_size)
	{
		if (sprite->h_offset + x >= 0 && sprite->h_offset + x
	< game->map_settings->resolution->width)
		{
			y = -1;
			while (++y < sprite->sprite_screen_size)
			{
				if (sprite->v_offset + y >= 0 && sprite->v_offset +
	y < game->map_settings->resolution->height)
				{
					if (return_texture_color_sprite(game->texture_sprite,
	sprite->sprite_screen_size, x, y) != 0x0)
						if (game->buffer_depth[sprite->h_offset + x]
	[sprite->v_offset + y] >= sprite->sprite_dist * game->map->scaled_to)
							buffer[sprite->h_offset + x][sprite->v_offset + y] =
	action(game, sprite, x, y);
				}
			}
		}
	}
}

void		sprites_iterate(t_game *game, t_sprite **sprites, float **buffer,
float (*action)(t_game *, t_sprite *, int, int))
{
	while (*sprites != NULL)
	{
		sprite_iterate_part(game, (*sprites), buffer, action);
		sprites += 1;
	}
}

void		sort_sprites(t_game *game, t_sprite **sprites)
{
	sprites_iterate(game, sprites, game->buffer_depth, sort);
}
