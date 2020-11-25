/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:11:16 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:02:41 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_H
# define GAME_UTILS_H
# include "../global_essences.h"
# include "../player/player_utils.h"
# include "../map/map_utils.h"
# include "../mlx/mlx_utils.h"
# include "../settings/settings_utils.h"
# include "../texture/texture_utils.h"
# include "../sprite/sprite_utils.h"
# include "game_essences.h"

t_answer		return_game(char *settings_file_path, t_game **game);
void			free_game(t_game *game);
t_answer		return_buffer_color(int rays_amount,
int height, float ***buffer_color);
t_answer		return_depth_buffer(int rays_amount,
int height, float ***depth_buffer);
t_answer		return_cast_result_h(t_ray_cast_result **cast_result_h);
t_answer		create_game(t_game **game);
t_answer		return_ray(t_ray **ray);
t_answer		return_cast_result_v(t_ray_cast_result **cast_result_v);
void			reset_game(t_game *game);

#endif
