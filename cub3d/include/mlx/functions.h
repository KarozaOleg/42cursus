/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:14:10 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/05 16:12:50 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "../../include/mlx/essences.h"
# include "../../include/global.h"

t_answer	return_mlx(t_mlx_my **mlx_my, t_resolution *resolution);
void		free_mlx(t_mlx_my *mlx_my);

void	draw_map(t_mlx_my *mlx_my, int **map);
void	draw_the_line(t_mlx_my *mlx_my);
void	draw_the_square(t_mlx_my *mlx_my);

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);
int		return_white();
#endif