/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:51:27 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/24 21:35:43 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/screenshot/screenshot_utils.h"

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

t_answer	buffer_to_screenshot(t_game *game)
{
	t_screenshot	screenshot;
	int				fd;
	
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0644);
	if(fd < 0)
		return (ERROR);
	return_screenshot_spec(game->map_settings->resolution, &screenshot);
	write_screenshot_spec(fd, &screenshot);
	write_buffer_color(fd, game);
	close(fd);
	ft_putstr("screenshot saved\n");
	return (SUCCESS);
}