/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:57:57 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 13:09:07 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/settings/settings_utils.h"

t_answer	parser_texture(char *line, void **value)
{
	*value = ft_strdup(line);
	return (SUCCESS);
}

t_parse_answer	parse_line_texture(char *line, t_map_settings *settings)
{	
	if(parser_base(line, "NO", parser_texture, (void *)(&settings->texture_no)) == FOUND)
		return (FOUND);

	if(parser_base(line, "SO", parser_texture, (void *)(&settings->texture_so)) == FOUND)
		return (FOUND);

	if(parser_base(line, "WE", parser_texture, (void *)(&settings->texture_we)) == FOUND)
		return (FOUND);

	if(parser_base(line, "EA", parser_texture, (void *)(&settings->texture_ea)) == FOUND)
		return (FOUND);

	if(parser_base(line, "S", parser_texture, (void *)(&settings->texture_s)) == FOUND)
		return (FOUND);

	return (NOT_FOUND);
}