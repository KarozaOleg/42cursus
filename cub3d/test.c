/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/15 18:51:46 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/game/game_utils.h"
#include "include/mlx/hooks.h"
#include "include/global.h"
#include "include/mlx/draw.h"
#include "test.h"
#include <stdio.h>

int test_leaks()
{
	char *file_path = "maps/map_corridor.cub";
	t_game *game = NULL;
	
	if(return_game(file_path, &game) == ERROR)
		return (ERROR);
		
	register_mlx_hook_key_pressed(game);
	mlx_loop(game->mlx_my->mlx);
	return (SUCCESS);
}

//gcc test*.c -g cub3d.a -framework OpenGL -framework AppKit -Lminilibx_mms -lmlx -Iminilibx_mms libmlx.dylib
//gcc test*.c cub3d.a libmlx_Linux.a -lXext -lX11 -lm -I.
int main()
{
	int answer = test_leaks();
	printf("exited\n");
	sleep(10);
	return (answer);
}

//TODO wall is so far, low resolution
//TODO bus error with collision sprite
//TODO check is map closed
//TODO check is more than one player
//TODO R 1200 639