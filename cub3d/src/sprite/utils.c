/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:16:29 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 14:11:54 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sprite/sprite_utils.h"
# include <stdio.h>

int	return_sprites_amount(int **map)
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

void	find_sprites_position(int **map, t_sprite **sprites)
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

void	calculate(t_game *game, t_sprite *sprite)
{
	t_player *player;
	int x;
	int y;
	
	player = game->player;
	x = sprite->x * game->map->scaled_to;
	y = sprite->y * game->map->scaled_to;

	sprite->sprite_dir = atan2(y - player->y, x - player->x);	
	sprite->sprite_dist = sqrt(pow(player->x/game->map->scaled_to - x/game->map->scaled_to, 2) + pow(player->y/game->map->scaled_to - y/game->map->scaled_to, 2));

	while (sprite->sprite_dir - player->pov >  PI) 
		sprite->sprite_dir -= 2*PI;
    while (sprite->sprite_dir - player->pov < -PI) 
		sprite->sprite_dir += 2*PI;

	sprite->sprite_screen_size = game->map_settings->resolution->height/sprite->sprite_dist;
	if (sprite->sprite_screen_size > game->map_settings->resolution->height * 2)
		sprite->sprite_screen_size = game->map_settings->resolution->height * 2;
	sprite->h_offset = (sprite->sprite_dir - player->pov) * (game->map_settings->resolution->width)/player->fov + game->map_settings->resolution->width/2 - sprite->sprite_screen_size/2;
	sprite->v_offset = game->map_settings->resolution->height/2.0 - sprite->sprite_screen_size/2.0;
}

void calculate_sprites(t_game *game)
{
	t_sprite *sprite;
	int s;
	
	s = 0;
	while(game->sprites[s] != NULL)
	{
		sprite = game->sprites[s];
		calculate(game, sprite);
		s += 1;
	}
}

void	sort_sprites(t_game *game, float **depth_buffer)
{
	int texture_x;
	int texture_y;
	int s;
	int color;
	
	s = 0;
	while(game->sprites[s] != NULL)
	{
		for (int i = 0; i < game->sprites[s]->sprite_screen_size; i++) 
		{
			if (game->sprites[s]->h_offset + i < 0 || game->sprites[s]->h_offset + i >= game->map_settings->resolution->width) 
				continue;
			for (int j = 0; j < game->sprites[s]->sprite_screen_size; j++) 
			{
				if (game->sprites[s]->v_offset + j < 0 || game->sprites[s]->v_offset + j >= game->map_settings->resolution->height) 
					continue;
				texture_x = i * 64 / game->sprites[s]->sprite_screen_size;
				texture_y = j * 64 / game->sprites[s]->sprite_screen_size;
				color = return_texture_color(game->texture_sprite, texture_x, texture_y);
				if(color == 0x0)
					continue;
				if(depth_buffer[game->sprites[s]->h_offset + i][game->sprites[s]->v_offset + j] > game->sprites[s]->sprite_dist)
					depth_buffer[game->sprites[s]->h_offset + i][game->sprites[s]->v_offset + j] = game->sprites[s]->sprite_dist;
			}
		}
		s += 1;
	}
}

void	draw_sprites(t_game *game, float **depth_buffer)
{
	int texture_x;
	int texture_y;
	int color;
	int s;

	s = 0;
	while(game->sprites[s] != NULL)
	{
		for (int i=0; i < game->sprites[s]->sprite_screen_size; i++) 
		{
			if (game->sprites[s]->h_offset + i < 0 || game->sprites[s]->h_offset + i >= game->map_settings->resolution->width) 
				continue;
			for (int j=0; j < game->sprites[s]->sprite_screen_size; j++) 
			{
				if(depth_buffer[game->sprites[s]->h_offset + i][game->sprites[s]->v_offset + j] < game->sprites[s]->sprite_dist)
					continue;
				if (game->sprites[s]->v_offset + j < 0 || game->sprites[s]->v_offset + j >= game->map_settings->resolution->height) 
					continue;					
				texture_x = i * 64 / game->sprites[s]->sprite_screen_size;
				texture_y = j * 64 / game->sprites[s]->sprite_screen_size;
				color = return_texture_color(game->texture_sprite, texture_x, texture_y);
				if(color == 0x0)
					continue;
				game->buffer_color[game->sprites[s]->h_offset + i][game->sprites[s]->v_offset + j] = color;
			}
		}
		s += 1;
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
