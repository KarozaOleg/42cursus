/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/23 22:07:35 by mgaston          ###   ########.fr       */
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
	char *file_path = "maps/map.cub";
	t_game *game = NULL;
	
	if(return_game(file_path, &game) == ERROR)
		return 1;		

	// print_map(game->map->array);
	
	register_mlx_hook_key_pressed(game);	
	mlx_loop(game->mlx_my->mlx);

	
	
	return (cub3d_exit("", game));
}

//gcc test*.c cub3d.a -lmlx -framework OpenGL -framework AppKit
//gcc test*.c cub3d.a libmlx_Linux.a -lXext -lX11 -lm
int main()
{
	int answer = test_leaks();
	sleep(0);
	return (answer);
}