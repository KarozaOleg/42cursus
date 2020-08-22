/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:04:52 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/22 18:16:29 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse/settings.h"

t_answer	parser_color(char *line, void **value)
{
	t_rgb *rgb;
	
	rgb = malloc(sizeof(t_rgb));
	if(rgb == NULL)
		return (ERROR);
	
	if (ft_isdigit(*line) == 0)
		return (ERROR);
	rgb->red = ft_atoi(line);
	line = skip_all(',', line);
	
	if (ft_isdigit(*line) == 0)
		return (ERROR);
	rgb->green = ft_atoi(line);
	line = skip_all(',', line);

	if (ft_isdigit(*line) == 0)
		return (ERROR);
	rgb->blue = ft_atoi(line);

	*value = (void *)rgb;
	return (SUCCESS);
}

t_parse_answer	parse_line_color(char *line, t_map_settings *settings)
{	
	if(parser_base(line, "F", parser_color, (void *)(&settings->color_floor)) == NOT_FOUND)
		return (NOT_FOUND);

	if(parser_base(line, "C", parser_color, (void *)(&settings->color_ceiling)) == NOT_FOUND)
		return (NOT_FOUND);
	
	return (FOUND);
}