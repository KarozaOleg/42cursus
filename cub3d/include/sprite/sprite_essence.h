/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_essence.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:38:35 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/14 18:17:50 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_ESSENCE_H
# define SPRITE_ESSENCE_H

typedef struct s_sprite
{	
	int x;
	int y;
	float sprite_dir;
	float sprite_dist;
	int sprite_screen_size;
	int h_offset;
	int v_offset;
}				t_sprite;

#endif