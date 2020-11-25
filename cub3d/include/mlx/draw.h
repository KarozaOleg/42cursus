/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:11:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/24 21:41:43 by mgaston          ###   ########.fr       */
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

#endif
