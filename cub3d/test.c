/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 20:23:24 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/global_essences.h"
#include "include/game/game_utils.h"
#include "include/mlx/hooks.h"
#include "include/global.h"
#include "include/mlx/draw.h"
#include "include/screenshot/screenshot_utils.h"
#include "test.h"
#include <stdio.h>

t_bool is_save_flag_exist(int argc, char **argv)
{
	char *str;

	str = "--save";
	if(argc > 2)
		if(ft_memcmp(str, argv[2], ft_strlen(str)) == 0)
			return (TRUE);
	return (FALSE);
}

int test_leaks(int argc, char **argv)
{
	t_game *game;

	game = NULL;
	if(argc < 2)
	{
		ft_putstr("wrong input\n");
		return 0;
	}
	if(return_game(argv[1], &game) == ERROR)
		return (ERROR);
	
	if(is_save_flag_exist(argc, argv) == TRUE)
	{
		scene_to_buffer(game);
		if(buffer_to_screenshot(game) == ERROR)
			ft_putstr("error saving screenshot\n");
	}
	else
	{
		register_mlx_hook_key_pressed(game);
		mlx_loop(game->mlx_my->mlx);
	}
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	int answer = test_leaks(argc, argv);
	printf("exited\n");
	sleep(10);
	return (answer);
}

//./a.out ./maps/map_corridor.cub --save
//maps/map_corridor.cub
//gcc test*.c -g cub3d.a -framework OpenGL -framework AppKit -Lminilibx_mms -lmlx -Iminilibx_mms libmlx.dylib
//gcc test*.c cub3d.a libmlx_Linux.a -lXext -lX11 -lm
//TODO wall is so far, low resolution
//TODO bus error with collision sprite
//TODO check is map closed
//TODO check is more than one player
//TODO R 1200 639
//TODO rename depth_buffer
//TODO rename num_rays
//TODO player start view
//TODO draw at start