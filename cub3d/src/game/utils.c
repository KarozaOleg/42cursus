/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:13:54 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/14 21:09:42 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/game/game_utils.h"
//TODO remove
#include <stdio.h>

t_answer	create_game(t_game **game)
{
	*game = malloc(sizeof(**game));
	if(*game == NULL)
		return (ERROR);
	printf("s>%p\n",*game);

	return (SUCCESS);
}

t_answer	return_ray(t_ray **ray)
{
	*ray = malloc(sizeof(**ray));
	if(*ray == NULL)
		return ERROR;
	return (SUCCESS);
}

t_answer	return_cast_result_h(t_ray_cast_result **cast_result_h)
{
	*cast_result_h = malloc(sizeof(**cast_result_h));
	if(*cast_result_h == NULL)
		return (ERROR);
	return (SUCCESS);
}

t_answer	return_cast_result_v(t_ray_cast_result **cast_result_v)
{
	*cast_result_v = malloc(sizeof(**cast_result_v));
	if(*cast_result_v == NULL)
		return (ERROR);
	return (SUCCESS);
}

t_answer	return_game(char *settings_file_path, t_game **game)
{
	t_ray *ray = NULL;
	t_map *map = NULL;
	t_map_settings *map_settings = NULL;
	t_mlx_my *mlx_my = NULL;
	t_player *player = NULL;
	t_sprite **sprites = NULL;
	t_image *texture_sprite = NULL;
	t_image **texture_wall = NULL;
	t_ray_cast_result *cast_result_h = NULL;
	t_ray_cast_result *cast_result_v = NULL;

	if(create_game(game) == ERROR)
		return (cub3d_exit("error, creating game", game));

	if(return_ray(&ray) == ERROR)
		return (cub3d_exit("error, creating ray", game));

	if(return_cast_result_h(&cast_result_h) == ERROR)
		return (cub3d_exit("error, creating cast result h", game));

	if(return_cast_result_v(&cast_result_v) == ERROR)
		return (cub3d_exit("error, creating cast result v", game));
		
	if(return_map(settings_file_path, &map) == ERROR)
		return (cub3d_exit("error, parsing map", game));
	
	if(is_map_valid(map) == ERROR)
		return (cub3d_exit("error, map is invalid", game));
	
	if(return_map_settings(settings_file_path, &map_settings) == ERROR)
		return (cub3d_exit("error, parsing settings", game));

	if(is_map_settings_valid(map_settings) == ERROR)
		return (cub3d_exit("error, settings is invalid", game));
	
	if(return_mlx(&mlx_my, map_settings->resolution) == ERROR)
		return (cub3d_exit("error, initialize mlx", game));
	
	if(return_player(map_settings->resolution->width, map->array, &player, map->scaled_to, map->minimap_ratio) == ERROR)
		return (cub3d_exit("error, initialize player", game));

	if(return_sprites(map->array, &sprites) == ERROR)
		return (cub3d_exit("error, find sprites", game));

	if(return_texture_wall(mlx_my->mlx, map_settings, &texture_wall) == ERROR)
		return (cub3d_exit("error, load texture wall", game));

	if(return_texture_sprite(mlx_my->mlx, map_settings->texture_s, &texture_sprite) == ERROR)
		return (cub3d_exit("error, load texture sprite", game));

	(*game)->ray = ray;
	// printf(">%p\n",(*game)->ray);
	(*game)->cast_result_horisontal = cast_result_h;
	(*game)->cast_result_vertical = cast_result_v;
	(*game)->map = map;
	(*game)->map_settings = map_settings;
	(*game)->mlx_my = mlx_my;
	(*game)->player = player;
	(*game)->sprites = sprites;
	(*game)->texture_wall = texture_wall;
	(*game)->texture_sprite = texture_sprite;
	
	return (SUCCESS);
}

//TODO fix it
void		free_game(t_game **game)
{	
	if(game == NULL)
		return ;
	if((*game)->ray == NULL)
		printf("is null\n");

	// printf("%p\n",(*game)->ray);
	free((*game)->ray);
	// free(game->cast_result_horisontal);
	// free(game->cast_result_vertical);
	// free_map(game->map);
	// free_map_settings(game->map_settings);
	// free_mlx(game->mlx_my);
	// free_player(game->player);
	// free_sprites(game->sprites);
	// free_texture_walls(game->texture_wall);
	// free_texture_sprite(game->texture_sprite);
	// free(game);
}