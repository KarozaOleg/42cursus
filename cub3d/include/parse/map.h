/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:28:52 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/23 14:56:12 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAP_EMPTY		0
# define MAP_WALL		1
# define MAP_SPRITE		2
# define MAP_UNIVERSE	3
# define MAP_PLAYER_N	4
# define MAP_PLAYER_S	5
# define MAP_PLAYER_E	6
# define MAP_PLAYER_W	7

# include "parse.h"

t_parse_answer	return_char2int_for_map(int value, int *converted);

t_answer		is_a_map_line(char *line);
t_answer		is_map_valid(int **map);

t_answer		return_map(char *file_name, int ***map);
void			free_map(int** map);

#endif
