/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:11:16 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/14 20:55:06 by mgaston          ###   ########.fr       */
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
void			free_game(t_game **game);

#endif