/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:11:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 15:36:11 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "mlx_essences.h"
# include "mlx_utils.h"
# include "colors.h"
# include "../player/player_essences.h"

int		draw_scene(t_game *game);
void	draw_map(t_mlx_img *scene, int **map, int increased_to);
void	draw_player(t_mlx_img *scene, t_player *player, int increased_to);
void	draw_the_line(t_mlx_img *scene);
void	draw_the_square(t_mlx_img *scene);

#endif

