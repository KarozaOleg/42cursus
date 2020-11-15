/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:14:10 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/15 12:57:16 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_FUNCTIONS_H
# define MLX_FUNCTIONS_H
# include "mlx_essences.h"
# include "../global.h"
# include "../global_essences.h"

t_answer	return_mlx(t_resolution *resolution, t_mlx_my **mlx_my);
void		free_mlx(t_mlx_my *mlx_my);

void		my_mlx_pixel_put(t_mlx_img *scene, int x, int y, int color);

#endif