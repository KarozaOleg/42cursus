/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/14 21:10:45 by mgaston          ###   ########.fr       */
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
		return 1;
	printf("m0>%p\n",game);
	
	// print_map(game->map->array);
	
	register_mlx_hook_key_pressed(&game);
	mlx_loop(game->mlx_my->mlx);
	printf("here2\n\n");
	return (0);
}

//gcc test*.c cub3d.a -lmlx -framework OpenGL -framework AppKit
//gcc test*.c cub3d.a libmlx_Linux.a -lXext -lX11 -lm
int main()
{
	int answer = test_leaks();
	printf("exited\n");
	sleep(10);
	return (answer);
}