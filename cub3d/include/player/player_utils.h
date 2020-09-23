/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:22:53 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/18 21:22:57 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_UTILS_H
# define PLAYER_UTILS_H

# include "../global.h"
# include "../global_essences.h"
# include "player_essences.h"

t_answer		return_player(int width, int **map, t_player **player, int scaled_to, float minimap_ratio);
void			free_player(t_player *player);

#endif