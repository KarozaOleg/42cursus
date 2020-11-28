/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 15:48:28 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/global_essences.h"
#include "include/game/game_utils.h"
#include "include/mlx/hooks.h"
#include "include/global.h"
#include "include/mlx/draw.h"
#include "include/screenshot/screenshot_utils.h"

t_bool	is_save_flag_exist(int argc, char **argv)
{
	char *str;

	str = "--save";
	if (argc > 2)
		if (ft_memcmp(str, argv[2], ft_strlen(str)) == 0)
			return (TRUE);
	return (FALSE);
}

int		main(int argc, char **argv)
{
	t_game *game;

	game = NULL;
	if (argc < 2)
	{
		ft_putstr("wrong input\n");
		return (0);
	}
	if (return_game(argv[1], &game) == ERROR)
		return (ERROR);
	if (is_save_flag_exist(argc, argv) == TRUE)
	{
		scene_to_buffer(game);
		if (buffer_to_screenshot(game) == ERROR)
			ft_putstr("error saving screenshot\n");
	}
	else
	{
		register_mlx_hook_key_pressed(game);
		draw_scene(game);
		mlx_loop(game->mlx_my->mlx);
	}
	return (SUCCESS);
}
