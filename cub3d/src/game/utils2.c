/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:13:54 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 23:08:32 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/game/game_utils.h"

t_answer	return_cast_result_v(t_ray_cast_result **cast_result_v)
{
	*cast_result_v = malloc(sizeof(**cast_result_v));
	if (*cast_result_v == NULL)
		return (ERROR);
	return (SUCCESS);
}

void		reset_game(t_game *game)
{
	game->ray = NULL;
	game->map = NULL;
	game->cast_result_horisontal = NULL;
	game->cast_result_vertical = NULL;
	game->map_settings = NULL;
	game->mlx_my = NULL;
	game->player = NULL;
	game->sprites = NULL;
	game->texture_sprite = NULL;
	game->texture_wall = NULL;
	game->buffer_color = NULL;
	game->buffer_depth = NULL;
	game->y_amount = 0;
}

t_answer	return_game3(t_game **game)
{
	if (return_depth_buffer((*game)->player->num_rays,
	(*game)->map_settings->resolution->height,
	&((*game)->buffer_depth)) == ERROR)
		return (cub3d_exit("error, create depth buffer", *game));
	if (return_buffer_color((*game)->player->num_rays,
	(*game)->map_settings->resolution->height,
	&((*game)->buffer_color)) == ERROR)
		return (cub3d_exit("error, create buffer color", *game));
	(*game)->y_amount = return_y_amount((*game)->map->array);
	return (SUCCESS);
}

t_answer	return_game2(t_game **game)
{
	if (return_mlx((*game)->map_settings->resolution,
	&((*game)->mlx_my)) == ERROR)
		return (cub3d_exit("error, initialize mlx", *game));
	if (return_player((*game), &((*game)->player)) == ERROR)
		return (cub3d_exit("error, initialize player", *game));
	if (return_sprites((*game)->map->array, &((*game)->sprites)) == ERROR)
		return (cub3d_exit("error, find sprites", *game));
	if (return_texture_sprite((*game)->mlx_my->mlx,
	(*game)->map_settings->texture_s,
	&((*game)->texture_sprite)) == ERROR)
		return (cub3d_exit("error, load texture sprite", *game));
	if (return_texture_wall((*game)->mlx_my->mlx, (*game)->map_settings,
	&((*game)->texture_wall)) == ERROR)
		return (cub3d_exit("error, load texture wall", *game));
	if (return_depth_buffer((*game)->player->num_rays,
	(*game)->map_settings->resolution->height,
	&((*game)->buffer_depth)) == ERROR)
		return (cub3d_exit("error, create depth buffer", *game));
	if (return_buffer_color((*game)->player->num_rays,
	(*game)->map_settings->resolution->height,
	&((*game)->buffer_color)) == ERROR)
		return (cub3d_exit("error, create buffer color", *game));
	(*game)->y_amount = return_y_amount((*game)->map->array);
	return (SUCCESS);
}

t_answer	return_game(char *settings_file_path, t_game **game)
{
	if (create_game(game) == ERROR)
		return (cub3d_exit("error, creating game", *game));
	reset_game(*game);
	if (return_ray(&((*game)->ray)) == ERROR)
		return (cub3d_exit("error, creating ray", *game));
	if (return_map(settings_file_path, &((*game)->map)) == ERROR)
		return (cub3d_exit("error, parsing map", *game));
	if (return_cast_result_h(&((*game)->cast_result_horisontal)) == ERROR)
		return (cub3d_exit("error, creating cast result h", *game));
	if (return_cast_result_v(&(*game)->cast_result_vertical) == ERROR)
		return (cub3d_exit("error, creating cast result v", *game));
	if (is_map_valid((*game)->map) == ERROR)
		return (cub3d_exit("error, map is invalid", *game));
	if (is_map_closed((*game)->map) == ERROR)
		return (cub3d_exit("error, map is not closed", *game));
	if (return_map_settings(settings_file_path,
	&((*game)->map_settings)) == ERROR)
		return (cub3d_exit("error, parsing settings", *game));
	if (is_colors_valid((*game)->map_settings) == ERROR)
		return (cub3d_exit("error, colors is invalid", *game));
	if (is_map_settings_valid((*game)->map_settings) == ERROR)
		return (cub3d_exit("error, settings is invalid", *game));
	return (return_game2(game));
}
