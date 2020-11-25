/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:22:53 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:41:03 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_UTILS_H
# define PLAYER_UTILS_H

# include "../global.h"
# include "../global_essences.h"
# include "player_essences.h"

t_answer	return_player(t_game *game, t_player **player);
void		free_player(t_player *player);
t_answer	init_player(t_player **player, int width);
t_answer	return_player_start_pov(int type, float *pov);
t_bool		is_a_player(int value);

#endif
