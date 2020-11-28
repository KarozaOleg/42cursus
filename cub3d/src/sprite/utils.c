/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:16:29 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 14:39:11 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sprite/sprite_utils.h"

int			return_sprites_amount(int **map)
{
	int amount;
	int y;
	int x;

	amount = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != -1)
		{
			if (map[y][x] == MAP_SPRITE)
				amount += 1;
			x += 1;
		}
		y += 1;
	}
	return (amount);
}

void		find_sprites_position(int **map, t_sprite **sprites)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != -1)
		{
			if (map[y][x] == MAP_SPRITE)
			{
				sprites[i]->x = x;
				sprites[i]->y = y;
				i += 1;
			}
			x += 1;
		}
		y += 1;
	}
}

t_answer	return_sprites(int **map, t_sprite ***sprites)
{
	int sprites_amount;

	sprites_amount = return_sprites_amount(map);
	*sprites = malloc(sizeof(*sprites) * (sprites_amount + 1));
	if (*sprites == NULL)
		return (ERROR);
	(*sprites)[sprites_amount] = NULL;
	while (--sprites_amount >= 0)
	{
		(*sprites)[sprites_amount] =
malloc(sizeof(*((*sprites)[sprites_amount])));
		if ((*sprites)[sprites_amount] == NULL)
			return (ERROR);
	}
	find_sprites_position(map, *sprites);
	return (SUCCESS);
}

void		calculate(t_game *game, t_sprite *sprite)
{
	int x;
	int y;

	x = sprite->x * game->map->scaled_to;
	y = sprite->y * game->map->scaled_to;
	sprite->sprite_dir = atan2(y - game->player->y, x - game->player->x);
	sprite->sprite_dist = distance_between_points(game->player->x /
	game->map->scaled_to, game->player->y / game->map->scaled_to, x /
	game->map->scaled_to, y / game->map->scaled_to);
	while (sprite->sprite_dir - game->player->pov > PI)
		sprite->sprite_dir -= 2 * PI;
	while (sprite->sprite_dir - game->player->pov < -PI)
		sprite->sprite_dir += 2 * PI;
	sprite->sprite_screen_size = game->map_settings->resolution->height /
	sprite->sprite_dist;
	if (sprite->sprite_screen_size > game->map_settings->resolution->height * 2)
		sprite->sprite_screen_size = game->map_settings->resolution->height * 2;
	sprite->h_offset = (sprite->sprite_dir - game->player->pov) *
	game->map_settings->resolution->width /
	game->player->fov + (game->map_settings->resolution->width /
	2) - sprite->sprite_screen_size;
	sprite->v_offset = game->map_settings->resolution->height / 2.0 -
	sprite->sprite_screen_size / 2.0;
}

void		calculate_sprites(t_game *game)
{
	int s;

	s = 0;
	while (game->sprites[s] != NULL)
	{
		calculate(game, game->sprites[s]);
		s += 1;
	}
}
