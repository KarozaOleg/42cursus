/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:16:29 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 17:29:37 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sprite/sprite_utils.h"
# include <stdio.h>

int			return_sprites_amount(int **map)
{
	int amount;
	int y;
	int x;

	amount = 0;
	y = 0;
	while(map[y] != NULL)
	{
		x = 0;
		while(map[y][x] != -1)
		{
			if(map[y][x] == MAP_SPRITE)
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
	while(map[y] != NULL)
	{
		x = 0;
		while(map[y][x] != -1)
		{
			if(map[y][x] == MAP_SPRITE)
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
	if(*sprites == NULL)
		return ERROR;
	(*sprites)[sprites_amount] = NULL;

	while(--sprites_amount >= 0)
		(*sprites)[sprites_amount] = malloc(sizeof(*((*sprites)[sprites_amount])));
	
	find_sprites_position(map, *sprites);
	return SUCCESS;
}

void		calculate(t_game *game, t_sprite *sprite)
{
	int x;
	int y;
	
	x = sprite->x * game->map->scaled_to;
	y = sprite->y * game->map->scaled_to;

	sprite->sprite_dir = atan2(y - game->player->y, x - game->player->x);	
	sprite->sprite_dist = sqrt(pow(game->player->x/game->map->scaled_to - x/game->map->scaled_to, 2) + pow(game->player->y/game->map->scaled_to - y/game->map->scaled_to, 2));

	while (sprite->sprite_dir - game->player->pov >  PI) 
		sprite->sprite_dir -= 2*PI;
    while (sprite->sprite_dir - game->player->pov < -PI) 
		sprite->sprite_dir += 2*PI;

	sprite->sprite_screen_size = game->map_settings->resolution->height/sprite->sprite_dist;
	if (sprite->sprite_screen_size > game->map_settings->resolution->height * 2)
		sprite->sprite_screen_size = game->map_settings->resolution->height * 2;
	sprite->h_offset = (sprite->sprite_dir - game->player->pov) * (game->map_settings->resolution->width)/game->player->fov + game->map_settings->resolution->width/2 - sprite->sprite_screen_size/2;
	sprite->v_offset = game->map_settings->resolution->height/2.0 - sprite->sprite_screen_size/2.0;
}

void		calculate_sprites(t_game *game)
{
	int s;
	
	s = 0;
	while(game->sprites[s] != NULL)
	{
		calculate(game, game->sprites[s]);
		s += 1;
	}
}

int			return_texture_color_sprite(t_image *image, int size, int x, int y)
{
	int texture_x;
	int texture_y;
	int color;

	texture_x = x * 64 / size;
	texture_y = y * 64 / size;

	color = return_texture_color(image, texture_x, texture_y);
	return (color);
}

void		sort_sprites(t_game *game, t_sprite **sprites, float **depth_buffer)
{
	int x;
	int y;
	int color;
	
	while(*sprites != NULL)
	{
		x = 0;
		while(x < (*sprites)->sprite_screen_size)
		{
			if ((*sprites)->h_offset + x >= 0 && (*sprites)->h_offset + x < game->map_settings->resolution->width) 
			{
				y = 0;
				while(y < (*sprites)->sprite_screen_size)
				{
					if ((*sprites)->v_offset + y >= 0 && (*sprites)->v_offset + y < game->map_settings->resolution->height) 
					{
						color = return_texture_color_sprite(game->texture_sprite, (*sprites)->sprite_screen_size, x, y);
						if(color != 0x0)
						{
							if(depth_buffer[(*sprites)->h_offset + x][(*sprites)->v_offset + y] > (*sprites)->sprite_dist)
								depth_buffer[(*sprites)->h_offset + x][(*sprites)->v_offset + y] = (*sprites)->sprite_dist;
						}
					}
					y += 1;
				}
			}
			x += 1;
		}
		sprites += 1;
	}
}

void	draw_sprites(t_game *game, t_sprite **sprites, float **depth_buffer)
{
	int x;
	int y;
	int color;
	
	while(*sprites != NULL)
	{
		x = 0;
		while(x < (*sprites)->sprite_screen_size)
		{
			if ((*sprites)->h_offset + x >= 0 && (*sprites)->h_offset + x < game->map_settings->resolution->width) 
			{
				y = 0;
				while(y < (*sprites)->sprite_screen_size)
				{
					if(depth_buffer[(*sprites)->h_offset + x][(*sprites)->v_offset + y] >= (*sprites)->sprite_dist)
					{					
						if ((*sprites)->v_offset + y >= 0 && (*sprites)->v_offset + y < game->map_settings->resolution->height) 
						{
							color = return_texture_color_sprite(game->texture_sprite, (*sprites)->sprite_screen_size, x, y);
							if(color != 0x0)
							{
								game->buffer_color[(*sprites)->h_offset + x][(*sprites)->v_offset + y] = color;
							}
						}
					}
					y += 1;
				}
			}
			x += 1;
		}
		sprites += 1;
	}
}

void free_sprites(t_sprite **sprites)
{
	int s;
	if(sprites == NULL)
		return;

	s = 0;
	while(sprites[s] != NULL)
	{
		free(sprites[s]);
		s += 1;
	}
	free(sprites);
}
