/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:22:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 12:27:34 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../global.h"
# include "../../gnl/get_next_line.h"

typedef enum	s_parse_answer
{
	FOUND,
	NOT_FOUND
}				t_parse_answer;

char			*skip_all(char c, char *line);
t_parse_answer	parser_base(char *line, char *name, t_answer (*parser)(char *line, void **value), void *value);

#endif

