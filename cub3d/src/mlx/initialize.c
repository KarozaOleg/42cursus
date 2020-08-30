/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:32:44 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 18:00:08 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/functions.h"
#include <stdio.h>

t_answer return_mlx(t_mlx_my **mlx_my)
{
	printf("here\n");
	*mlx_my = malloc(sizeof(**mlx_my));
	if (*mlx_my == NULL)
		return (ERROR);

		(*mlx_my)->mlx = NULL;
	printf("here%p\n",(*mlx_my)->mlx);
		
	(*mlx_my)->mlx = mlx_init();
    // (*mlx_my)->mlx_win = mlx_new_window((*mlx_my)->mlx, resolution->width, resolution->height, "There is no spoon");

    // (*mlx_my)->mlx_img->img = mlx_new_image((*mlx_my)->mlx, resolution->width, resolution->height);

	return (SUCCESS);
}