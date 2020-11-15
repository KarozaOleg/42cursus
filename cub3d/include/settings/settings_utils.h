/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:06:44 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/15 15:07:01 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_UTILS_H
# define SETTINGS_UTILS_H

# include "../parse/parse.h"
# include "../map/map_essences.h"

t_parse_answer	is_a_settings_line(char *line);
t_parse_answer	parse_line_resolution(char *line, t_map_settings *map_settings);
t_parse_answer	parse_line_texture(char *line, t_map_settings *map_settings);
t_parse_answer	parse_line_color(char *line, t_map_settings *map_settings);
t_answer		return_map_settings(char *file_name, t_map_settings **map_settings);
t_answer		is_map_settings_valid(t_map_settings *map_settings);
void			initialize_map_settings(t_map_settings *map_settings);
void			free_map_settings(t_map_settings *map_settings);

#endif