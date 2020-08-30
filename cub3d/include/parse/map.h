/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:28:52 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 14:38:24 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "parse.h"

t_parse_answer	return_char2int_for_map(int value, int *converted);

t_answer		is_a_map_line(char *line);
t_answer		is_map_valid(int **map);

t_answer		return_map(char *file_name, int ***map);
void			free_map(int **map);

#endif
