/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 14:22:33 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/global_essences.h"
#include "include/game/game_utils.h"
#include "include/mlx/hooks.h"
#include "include/global.h"
#include "include/mlx/draw.h"
#include "test.h"
#include <stdio.h>

typedef struct	s_screenshot
{
	char signature[2];
	int filesize;
	int reserved;
	int offset;
	int header_size;
	int dimension[2];
	short planes;
	short bpp;
	int compression;
	int size;
	int resolution[2];
	int pltcolor;
	int impcolor;
}			t_screenshot;


void	return_screenshot_spec(t_resolution *resolution, t_screenshot *screenshot)
{
	screenshot->signature[0] = 'B';
	screenshot->signature[1] = 'M';
	screenshot->filesize = 54 + 4 * resolution->width * resolution->height;
	screenshot->reserved = 0;
	screenshot->offset = 54;
	screenshot->header_size = 40;
	screenshot->dimension[0] = resolution->width;
	screenshot->dimension[1] = resolution->height;
	screenshot->planes = 1;
	screenshot->bpp = 32;
	screenshot->compression = 0;
	screenshot->size = resolution->width * resolution->height * 4;
	screenshot->resolution[0] = 2795;
	screenshot->resolution[1] = 2795;
	screenshot->pltcolor = 0;
	screenshot->impcolor = 0;
}

void	write_screenshot_spec(int fd, t_screenshot *screenshot)
{
	write(fd, (char*)screenshot->signature, sizeof(screenshot->signature));
	write(fd, (char*)&screenshot->filesize, sizeof(screenshot->filesize));
	write(fd, (char*)&screenshot->reserved, sizeof(screenshot->reserved));
	write(fd, (char*)&screenshot->offset, sizeof(screenshot->offset));
	write(fd, (char*)&screenshot->header_size, sizeof(screenshot->header_size));
	write(fd, (char*)screenshot->dimension, sizeof(screenshot->dimension));
	write(fd, (char*)&screenshot->planes, sizeof(screenshot->planes));
	write(fd, (char*)&screenshot->bpp, sizeof(screenshot->bpp));
	write(fd, (char*)&screenshot->compression, sizeof(screenshot->compression));
	write(fd, (char*)&screenshot->size, sizeof(screenshot->size));
	write(fd, (char*)screenshot->resolution, sizeof(screenshot->resolution));
	write(fd, (char*)&screenshot->pltcolor, sizeof(screenshot->pltcolor));
	write(fd, (char*)&screenshot->impcolor, sizeof(screenshot->impcolor));
}

void	write_buffer_color(int fd, t_game *game)
{
	int x;
	int y;

	y = game->map_settings->resolution->height;
	while(y >= 0)
	{
		x = 0;
		while(x < game->player->num_rays)
		{
			int color = game->buffer_color[x][y];
			write(fd, (char *)&color, sizeof(color));
			x += 1;
		}
		y -= 1;
	}
}

t_bool	draw_buffer_to_screenshot(t_game *game)
{
	t_screenshot screenshot;
	int fd;
	
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0644);
	if(fd < 0)
		return (FALSE);

	return_screenshot_spec(game->map_settings->resolution, &screenshot);
	write_screenshot_spec(fd, &screenshot);
	write_buffer_color(fd, game);
	close(fd);
	ft_putstr("screenshot saved\n");
	return (TRUE);
}

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
	t_bool is_save_screenshot;
	
	if(argc < 2)
	{
		ft_putstr("wrong input\n");
		return 0;
	}

	game = NULL;
	is_save_screenshot = is_save_flag_exist(argc, argv);
		
	if(return_game(argv[1], &game) == ERROR)
		return (ERROR);
	
	if(is_save_screenshot == TRUE)
	{
		draw_projection_plane_to_buffer(game);
		draw_buffer_to_screenshot(game);
		exit(0);
	}
		
	register_mlx_hook_key_pressed(game);
	mlx_loop(game->mlx_my->mlx);
	return (SUCCESS);
}

//./a.out ./maps/map_corridor.cub --save
//maps/map_corridor.cub
//gcc test*.c -g cub3d.a -framework OpenGL -framework AppKit -Lminilibx_mms -lmlx -Iminilibx_mms libmlx.dylib
//gcc test*.c cub3d.a libmlx_Linux.a -lXext -lX11 -lm
int main(int argc, char **argv)
{
	int answer = test_leaks(argc, argv);
	printf("exited\n");
	sleep(10);
	return (answer);
}

//TODO wall is so far, low resolution
//TODO bus error with collision sprite
//TODO check is map closed
//TODO check is more than one player
//TODO R 1200 639
//TODO rename depth_buffer
//TODO rename num_rays