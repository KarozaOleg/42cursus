/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:11:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/14 18:48:01 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "mlx_utils.h"
# include "colors.h"
#include "../game/game_essences.h"
#include "../texture/texture_utils.h"
#include "../sprite/sprite_utils.h"

int		draw_scene(t_game *game);
void	draw_line(t_mlx_img *scene, int x1, int x2, int y1, int y2, int color);
t_answer	draw_projection_plane(t_game *game);

#endif

