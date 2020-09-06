/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_essences.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:32:13 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 11:58:21 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_ESSENCES_H
# define PLAYER_ESSENCES_H

# include "../global.h"

typedef struct	s_player
{
	int start_position;
	int x;
	int y;
	int color;
}				t_player;

t_answer		intialize(int **map, t_player *player);

#endif