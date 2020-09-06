/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:11:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 13:39:39 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "mlx_essences.h"
# include "mlx_utils.h"
# include "colors.h"
# include "../player/player_essences.h"

void	draw_map(t_mlx_my *mlx_my, int **map);
void	draw_player(t_mlx_my *mlx_my, t_player *player);

void	draw_the_line(t_mlx_my *mlx_my);
void	draw_the_square(t_mlx_my *mlx_my);

#endif

