/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:17:38 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 15:45:05 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/texture/texture_utils.h"

int			return_texture_color(t_image *texture, int x, int y)
{
	char	*dst;
	int		color;

	dst = texture->addr + (y * texture->sl + x * (texture->bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

t_answer	return_texture_sprite(void *mlx, char *file_path_sprite,
t_image **texture_sprite)
{
	int width;
	int height;

	*texture_sprite = malloc(sizeof(**texture_sprite));
	if (*texture_sprite == NULL)
		return (ERROR);
	(*texture_sprite)->img = mlx_xpm_file_to_image(mlx,
file_path_sprite, &width, &height);
	(*texture_sprite)->addr = (char *)mlx_get_data_addr((*texture_sprite)->img,
&((*texture_sprite)->bpp), &((*texture_sprite)->sl),
&((*texture_sprite)->endl));
	return (SUCCESS);
}

t_answer	return_texture_wall_file_path(int i, t_map_settings *map_settings,
char **file_path)
{
	if (i == 0)
		*file_path = map_settings->texture_no;
	else if (i == 1)
		*file_path = map_settings->texture_so;
	else if (i == 2)
		*file_path = map_settings->texture_we;
	else if (i == 3)
		*file_path = map_settings->texture_ea;
	else
		return (ERROR);
	return (SUCCESS);
}

t_answer	return_texture_wall(void *mlx, t_map_settings *map_settings,
t_image ***texture_wall)
{
	int		width;
	int		height;
	int		i;
	char	*file_path_texture;

	*texture_wall = malloc(sizeof(*texture_wall) * 4);
	if (*texture_wall == NULL)
		return (ERROR);
	i = 0;
	while (i < 4)
	{
		if (return_texture_wall_file_path(i, map_settings,
	&file_path_texture) == ERROR)
			return (ERROR);
		(*texture_wall)[i] = malloc(sizeof(*((*texture_wall)[i])));
		if ((*texture_wall)[i] == NULL)
			return (ERROR);
		(*texture_wall)[i]->img = mlx_xpm_file_to_image(mlx,
	file_path_texture, &width, &height);
		(*texture_wall)[i]->addr = (char *)mlx_get_data_addr(
(*texture_wall)[i]->img, &((*texture_wall)[i]->bpp),
&((*texture_wall)[i]->sl), &((*texture_wall)[i]->endl));
		i += 1;
	}
	return (SUCCESS);
}
