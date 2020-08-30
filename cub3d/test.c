/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 17:52:10 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/parse/map.h"
#include "include/parse/settings.h"
#include "include/mlx/functions.h"
#include "include/global.h"
#include "test.h"

int test_leaks()
{
	char *file_path = "map.cub";
	t_map_settings *settings = NULL;
	int **map = NULL;
	t_mlx_my *mlx_my = NULL;

	// if(return_map(file_path, &map) == ERROR)
	// 	return (cub3d_exit("error, parsing map", settings, map, mlx_my));
	
	// if(is_map_valid(map) == ERROR)
	// 	return (cub3d_exit("error, map is invalid", settings, map, mlx_my));
	
	if(return_settings(file_path, &settings) == ERROR)
		return (cub3d_exit("error, parsing settings", settings, map, mlx_my));

	if(is_settings_valid(settings) == ERROR)
		return (cub3d_exit("error, settings is invalid", settings, map, mlx_my));
	
	if(return_mlx(&mlx_my) == ERROR)	
		return (cub3d_exit("error, initialize mlx", settings, map, mlx_my));	
		
	// mlx_loop(mlx_my->mlx);
	// print_map(map);
	// print_settings(settings);
	return (cub3d_exit("", settings, map, mlx_my));
}

//gcc test*.c cub3d.a -lmlx -framework OpenGL -framework AppKit
int main()
{
	int answer = test_leaks();
	sleep(60);
	return (answer);
}