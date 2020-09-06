/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_essences.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:32:13 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 15:45:25 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_ESSENCES_H
# define PLAYER_ESSENCES_H

typedef enum	s_player_move
{
	LEFT,
	RIGHT,
	DOWN,
	UP
}				t_player_move;

typedef struct	s_player
{
	int start_position;
	int x;
	int y;
	int color;
}				t_player;

#endif