/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:11:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 13:39:44 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "mlx_utils.h"
# include "colors.h"
# include "../game/game_essences.h"
# include "../texture/texture_utils.h"
# include "../sprite/sprite_utils.h"
# include "../ray_casting/ray_casting_utils.h"
# include "../ray_casting/ray_casting_essences.h"

int		draw_scene(t_game *game);
void	draw_line(t_mlx_img *scene, int x1, int x2, int y1, int y2, int color);
void	scene_to_buffer(t_game *game);
void	fill_buffer_color_wall(t_game *game, t_wall_spec *wall_spec);
void	fill_buffer_color_floor(t_game *game, int x1);
void	draw_buffer(t_game *game);
int		return_int_from_trgb(int t, t_rgb *rgb);

#endif
