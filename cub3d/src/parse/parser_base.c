/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:26:11 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:30:21 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse/parse.h"

char			*skip_all(char c, char *line)
{
	if (line != NULL)
	{
		line = ft_strchr(line, c);
		while (*line != '\0' && *line == c)
			line++;
	}
	return (line);
}

t_parse_answer	parser_base(char *line, char *name,
t_answer (*parser)(char *line, void **value), void *value)
{
	if (ft_strnstr(line, name, ft_strlen(name)) == NULL)
		return (NOT_FOUND);
	line = skip_all(' ', line);
	if (line == NULL)
		return (NOT_FOUND);
	if (parser(line, value) == ERROR)
		return (NOT_FOUND);
	return (FOUND);
}
