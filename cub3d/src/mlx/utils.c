/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:54:24 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:27:01 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/mlx_utils.h"

void		my_mlx_pixel_put(t_mlx_img *scene, int x, int y, int color)
{
	char	*dst;

	dst = scene->addr + (y * scene->line_length + x
	* (scene->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		validate_resolution(void *mlx, t_resolution *resolution)
{
	int screen_width;
	int screen_height;

	mlx_get_screen_size(mlx, &screen_width, &screen_height);
	if (resolution->width > screen_width)
		resolution->width = screen_width;
	if (resolution->height > screen_height)
		resolution->height = screen_height;
}

t_answer	return_mlx(t_resolution *resolution, t_mlx_my **mlx_my)
{
	if (mlx_my == NULL)
		return (ERROR);
	*mlx_my = malloc(sizeof(**mlx_my));
	if (*mlx_my == NULL)
		return (ERROR);
	(*mlx_my)->mlx = NULL;
	(*mlx_my)->win = NULL;
	(*mlx_my)->scene = NULL;
	(*mlx_my)->scene = malloc(sizeof(*((*mlx_my)->scene)));
	if ((*mlx_my)->scene == NULL)
		return (ERROR);
	(*mlx_my)->mlx = mlx_init();
	validate_resolution((*mlx_my)->mlx, resolution);
	(*mlx_my)->win = mlx_new_window((*mlx_my)->mlx,
resolution->width, resolution->height, "There is no spoon");
	if ((*mlx_my)->win == NULL)
		return (ERROR);
	(*mlx_my)->scene->img = mlx_new_image((*mlx_my)->mlx,
resolution->width, resolution->height);
	if ((*mlx_my)->scene->img == NULL)
		return (ERROR);
	(*mlx_my)->scene->addr = mlx_get_data_addr((*mlx_my)->scene->img,
&((*mlx_my)->scene)->bits_per_pixel,
&((*mlx_my)->scene)->line_length, &((*mlx_my)->scene)->endian);
	return (SUCCESS);
}

void		free_mlx(t_mlx_my *mlx_my)
{
	if (mlx_my == NULL)
		return ;
	if (mlx_my->scene != NULL)
		free(mlx_my->scene);
	if (mlx_my->win != NULL)
		mlx_destroy_window(mlx_my->mlx, mlx_my->win);
	if (mlx_my->mlx != NULL)
		free(mlx_my->mlx);
	free(mlx_my);
}
