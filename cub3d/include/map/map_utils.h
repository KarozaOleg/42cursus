/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:28:52 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 13:28:38 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "../parse/parse.h"
# include "../global.h"

t_parse_answer	return_char2int_for_map(int value, int *converted);

t_answer		is_a_map_line(char *line);
t_answer		is_map_valid(t_map *map);
t_answer		is_map_closed(t_map *map);
t_answer		is_colors_valid(t_map_settings *map_settings);
t_answer		return_map(char *file_name, t_map **map);
void			free_map(t_map *map);

#endif
