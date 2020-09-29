/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_essences.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:32:13 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/29 18:13:26 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_ESSENCES_H
# define PLAYER_ESSENCES_H

typedef enum	s_player_move
{
	LEFT,
	RIGHT,
	BACK,
	FRONT
}				t_player_move;

typedef struct	s_player
{
	int start_position;
	float x;
	float y;
	int color;
	float move_speed;
	float fov;
	float pov;
	float pov_step;
	int num_rays;
}				t_player;

#endif