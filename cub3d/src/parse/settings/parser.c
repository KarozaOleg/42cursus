/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:30:39 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 16:38:56 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse/settings.h"

t_answer	parser_settings_line(char *line, t_map_settings *settings)
{
	if (line == NULL)
		return (ERROR);
		
	if (ft_strlen(line) < 1)
		return (SUCCESS);

	if (is_a_settings_line(line) == NOT_FOUND)
		return (SUCCESS);	

	if (parse_line_resolution(line, settings) == FOUND)
		return (SUCCESS);

	if (parse_line_texture(line, settings) == FOUND)
		return (SUCCESS);

	if (parse_line_color(line, settings) == FOUND)
		return (SUCCESS);

	return (ERROR);
}

t_answer	parse_settings(char *file_name, t_map_settings *settings)
{
	int		answer;
	char	*line;
	int		fd;

	answer = 0;
	fd = open(file_name, 0);
	line = NULL;
	
	while((answer = get_next_line(fd, &line)) > 0)
	{
		if(parser_settings_line(line, settings) == ERROR)
			return (ERROR);
		free(line);
	}

	if(line != NULL)
	{
		if(parser_settings_line(line, settings) == ERROR)
			return (ERROR);
		free(line);
	}
	
	if (answer == -1)
		return (ERROR);
			
	close(fd);
	return (SUCCESS);
}

t_answer	return_settings(char *file_name, t_map_settings **settings)
{
	*settings = malloc(sizeof(**settings));
	if(*settings == NULL)
		return (ERROR);

	initialize_settings(*settings);
	
	if(parse_settings(file_name, *settings) == ERROR)
		return (ERROR);
	
	return (SUCCESS);
}
