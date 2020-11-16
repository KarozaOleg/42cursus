/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:13:54 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/16 23:03:00 by mgaston          ###   ########.fr       */
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

t_answer	return_depth_buffer(int rays_amount, int height, float ***depth_buffer)
{
	int i;

	(*depth_buffer) = malloc(sizeof(*depth_buffer) * (1 + rays_amount));
	if((*depth_buffer) == NULL)
		return (ERROR);
	(*depth_buffer)[rays_amount] = NULL;
	
	 i = 0;
	 while(i < rays_amount)
	 {
		(*depth_buffer)[i] = malloc(sizeof(***depth_buffer) * height);
		if((*depth_buffer)[i] == NULL)
			return (ERROR);
		 i += 1;
	 }
	 return (SUCCESS);
}

t_answer	return_buffer_color(int rays_amount, int height, int ***buffer_color)
{
	int i;

	(*buffer_color) = malloc(sizeof(*buffer_color) * (1 + rays_amount));
	if((*buffer_color) == NULL)
		return (ERROR);
	(*buffer_color)[rays_amount] = NULL;
	
	 i = 0;
	 while(i < rays_amount)
	 {
		(*buffer_color)[i] = malloc(sizeof(***buffer_color) * height);
		if((*buffer_color)[i] == NULL)
			return (ERROR);
		 i += 1;
	 }
	 return (SUCCESS);
}

t_answer	return_game(char *settings_file_path, t_game **game)
{
	if(create_game(game) == ERROR)
		return (cub3d_exit("error, creating game", *game));
		
	(*game)->ray = NULL;
	(*game)->cast_result_horisontal = NULL;
	(*game)->cast_result_vertical = NULL;
	(*game)->map = NULL;
	(*game)->map_settings = NULL;
	(*game)->mlx_my = NULL;
	(*game)->player = NULL;
	(*game)->sprites = NULL;
	(*game)->texture_sprite = NULL;
	(*game)->texture_wall = NULL;
	(*game)->buffer_color = NULL;
	(*game)->depth_buffer = NULL;

	if(return_ray(&((*game)->ray)) == ERROR)
		return (cub3d_exit("error, creating ray", *game));

	if(return_cast_result_h(&((*game)->cast_result_horisontal)) == ERROR)
		return (cub3d_exit("error, creating cast result h", *game));

	if(return_cast_result_v(&(*game)->cast_result_vertical) == ERROR)
		return (cub3d_exit("error, creating cast result v", *game));
		
	if(return_map(settings_file_path, &((*game)->map)) == ERROR)
		return (cub3d_exit("error, parsing map", *game));	
	
	if(is_map_valid((*game)->map) == ERROR)
		return (cub3d_exit("error, map is invalid", *game));
	
	if(return_map_settings(settings_file_path, &((*game)->map_settings)) == ERROR)
		return (cub3d_exit("error, parsing settings", *game));

	if(is_map_settings_valid((*game)->map_settings) == ERROR)
		return (cub3d_exit("error, settings is invalid", *game));
	
	if(return_mlx((*game)->map_settings->resolution, &((*game)->mlx_my)) == ERROR)
		return (cub3d_exit("error, initialize mlx", *game));
	
	if(return_player((*game)->map_settings->resolution->width, (*game)->map->array, (*game)->map->scaled_to, (*game)->map->minimap_ratio, &((*game)->player)) == ERROR)
		return (cub3d_exit("error, initialize player", *game));

	if(return_sprites((*game)->map->array, &((*game)->sprites)) == ERROR)
		return (cub3d_exit("error, find sprites", *game));

	if(return_texture_sprite((*game)->mlx_my->mlx, (*game)->map_settings->texture_s, &((*game)->texture_sprite)) == ERROR)
		return (cub3d_exit("error, load texture sprite", *game));

	if(return_texture_wall((*game)->mlx_my->mlx, (*game)->map_settings, &((*game)->texture_wall)) == ERROR)
		return (cub3d_exit("error, load texture wall", *game));

	if(return_depth_buffer((*game)->player->num_rays, (*game)->map_settings->resolution->height, &((*game)->depth_buffer)) == ERROR)
		return (cub3d_exit("error, create depth buffer", *game));

	if(return_buffer_color((*game)->player->num_rays, (*game)->map_settings->resolution->height, &((*game)->buffer_color)) == ERROR)
		return (cub3d_exit("error, create buffer color", *game));

	return (SUCCESS);
}

//TODO fix it
void		free_game(t_game *game)
{	
	if(game == NULL)
		return ;
	if(game->ray != NULL)
		free(game->ray);
	if(game->cast_result_horisontal != NULL)
		free(game->cast_result_horisontal);
	if(game->cast_result_vertical != NULL)
		free(game->cast_result_vertical);
	free_map(game->map);
	free_map_settings(game->map_settings);
	free_mlx(game->mlx_my);
	free_player(game->player);
	free_sprites(game->sprites);
	free_texture_sprite(game->texture_sprite);
	free_texture_walls(game->texture_wall);
	int i = 0;
	//TODO: check this
	while(game->depth_buffer[i] != NULL)
	{
		free(game->depth_buffer[i]);
		i += 1;
	}
	free(game->depth_buffer);
	free(game);
}