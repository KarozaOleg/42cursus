/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:11:16 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 15:25:43 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_H
# define GAME_UTILS_H
# include "../global.h"
# include "game_essences.h"
# include "../mlx/mlx_utils.h"
# include "../map/map_utils.h"
# include "../player/player_utils.h"
# include "../settings/settings_utils.h"

t_answer		return_game(char *settings_file_path, t_game **game);
void			free_game(t_game *game);

#endif