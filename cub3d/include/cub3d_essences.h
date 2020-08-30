/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_essences.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:21:02 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 13:17:00 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ESSENCES_H
# define CUB3D_ESSENCES_H

# define MAP_EMPTY		0
# define MAP_WALL		1
# define MAP_SPRITE		2
# define MAP_UNIVERSE	3
# define MAP_PLAYER_N	4
# define MAP_PLAYER_S	5
# define MAP_PLAYER_E	6
# define MAP_PLAYER_W	7

typedef struct	s_rgb
{
	int	red;
	int green;
	int blue;
}				t_rgb;

typedef struct	s_resolution
{
	int	width;
	int height;
}				t_resolution;

typedef struct	s_map_settings
{
	t_resolution *resolution;
	char *texture_no;
	char *texture_so;
	char *texture_we;
	char *texture_ea;
	char *texture_s;
	t_rgb *color_floor;
	t_rgb *color_ceiling;
}				t_map_settings;

#endif