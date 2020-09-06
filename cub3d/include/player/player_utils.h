/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:22:53 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 18:06:09 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_UTILS_H
# define PLAYER_UTILS_H

# include "../global.h"
# include "../global_essences.h"
# include "player_essences.h"

t_answer		return_player(int **map, t_player **player);
void			free_player(t_player *player);

#endif