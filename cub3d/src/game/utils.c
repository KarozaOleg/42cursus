/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:13:54 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/23 20:38:46 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/game/game_utils.h"

t_answer	create_game(t_game **game)
{
	*game = malloc(sizeof(**game));
	if(*game == NULL)
		return (ERROR);

	return (SUCCESS);
}

t_answer	return_game(char *settings_file_path, t_game **game)
{
	t_map *map = NULL;
	t_map_settings *map_settings = NULL;
	t_mlx_my *mlx_my = NULL;
	t_player *player = NULL;

	if(create_game(game) == ERROR)
		return (cub3d_exit("error, creating game", *game));
		
	if(return_map(settings_file_path, &map) == ERROR)
		return (cub3d_exit("error, parsing map", *game));
	
	if(is_map_valid(map) == ERROR)
		return (cub3d_exit("error, map is invalid", *game));
	
	if(return_map_settings(settings_file_path, &map_settings) == ERROR)
		return (cub3d_exit("error, parsing settings", *game));

	if(is_map_settings_valid(map_settings) == ERROR)
		return (cub3d_exit("error, settings is invalid", *game));
	
	if(return_mlx(&mlx_my, map_settings->resolution) == ERROR)
		return (cub3d_exit("error, initialize mlx", *game));
	
	if(return_player(map_settings->resolution->width, map->array, &player, map->scaled_to, map->minimap_ratio) == ERROR)
		return (cub3d_exit("error, initialize player", *game));

	(*game)->map = map;
	(*game)->map_settings = map_settings;
	(*game)->mlx_my = mlx_my;
	(*game)->player = player;

	return (SUCCESS);
}

void		free_game(t_game *game)
{	
	if(game == NULL)
		return ;
		
	//TODO fix it
	free_map_settings(game->map_settings);
	free_map(game->map);
	// free_mlx(game->mlx_my);	
	// free_player(game->player);	
}