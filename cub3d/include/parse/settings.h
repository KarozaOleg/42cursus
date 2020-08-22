/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:31:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/22 18:14:54 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include "parse.h"

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

t_parse_answer	parse_line_resolution(char *line, t_map_settings *settings);
t_parse_answer	parse_line_texture(char *line, t_map_settings *settings);
t_parse_answer	parse_line_color(char *line, t_map_settings *settings);
t_answer		return_settings(char *file_name, t_map_settings **settings);

#endif