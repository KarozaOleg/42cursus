/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_essences.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:18:08 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 16:43:14 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ESSENCES_H
# define MAP_ESSENCES_H

# include "../mlx/mlx_essences.h"

# define MAP_EMPTY		0
# define MAP_WALL		1
# define MAP_SPRITE		2
# define MAP_UNIVERSE	3
# define MAP_PLAYER_N	4
# define MAP_PLAYER_S	5
# define MAP_PLAYER_E	6
# define MAP_PLAYER_W	7

typedef struct s_restriction
{
	int min;
	int max;
}				t_restriction;
typedef struct	s_map
{
	int **array;
	t_restriction **restrictions_x;
	t_restriction **restrictions_y;
	int increased_to;
}				t_map;

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