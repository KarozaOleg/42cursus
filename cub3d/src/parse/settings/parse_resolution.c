/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:04:24 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 14:27:16 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse/settings.h"

t_answer	parser_resolution(char *line, void **value)
{
	t_resolution *resolution;

	resolution = malloc(sizeof(*resolution));
	if(resolution == NULL)
		return (ERROR);
	
	if (ft_isdigit(*line) == 0)
		return (ERROR);
	resolution->width = ft_atoi(line);	
	line = skip_all(' ', line);
	if(line == NULL)
		return (ERROR);
	
	if (ft_isdigit(*line) == 0)
		return (ERROR);
	resolution->height = ft_atoi(line);

	*value = (void *)resolution;
	return (SUCCESS);
}

t_parse_answer	parse_line_resolution(char *line, t_map_settings *settings)
{	
	if(parser_base(line, "R", parser_resolution, (void *)(&settings->resolution)) == FOUND)
		return (FOUND);
	
	return (NOT_FOUND);
}