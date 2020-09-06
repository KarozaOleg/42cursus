/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 16:51:20 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/game/game_utils.h"
#include "include/mlx/hooks.h"
#include "include/global.h"
#include "include/mlx/draw.h"
#include "test.h"

int test_leaks()
{
	char *file_path = "maps/map_easy.cub";
	t_game *game = NULL;
	
	if(return_game(file_path, &game) == ERROR)
		return 1;
	
	register_mlx_hook_key_pressed(game);
	mlx_loop(game->mlx_my->mlx);
	
	return (cub3d_exit("", game));
}

//gcc test*.c cub3d.a -lmlx -framework OpenGL -framework AppKit
int main()
{
	int answer = test_leaks();
	sleep(0);
	return (answer);
}