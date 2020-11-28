/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:30:39 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 14:31:25 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/settings/settings_utils.h"

t_answer	parser_map_settings_line(char *line, t_map_settings *map_settings)
{
	if (line == NULL)
		return (ERROR);
	if (ft_strlen(line) < 1)
		return (SUCCESS);
	if (is_a_settings_line(line) == NOT_FOUND)
		return (SUCCESS);
	if (parse_line_resolution(line, map_settings) == FOUND)
		return (SUCCESS);
	if (parse_line_texture(line, map_settings) == FOUND)
		return (SUCCESS);
	if (parse_line_color(line, map_settings) == FOUND)
		return (SUCCESS);
	return (ERROR);
}

t_answer	parse_map_settings(char *file_name, t_map_settings *map_settings)
{
	int		answer;
	char	*line;
	int		fd;

	answer = 0;
	fd = open(file_name, 0);
	line = NULL;
	while ((answer = get_next_line(fd, &line)) > 0)
	{
		if (parser_map_settings_line(line, map_settings) == ERROR)
			return (ERROR);
		free(line);
	}
	if (line != NULL)
	{
		if (parser_map_settings_line(line, map_settings) == ERROR)
			return (ERROR);
		free(line);
	}
	if (answer == -1)
		return (ERROR);
	close(fd);
	return (SUCCESS);
}

t_answer	return_map_settings(char *file_name, t_map_settings **map_settings)
{
	*map_settings = malloc(sizeof(**map_settings));
	if (*map_settings == NULL)
		return (ERROR);
	initialize_map_settings(*map_settings);
	if (parse_map_settings(file_name, *map_settings) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
