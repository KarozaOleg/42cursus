/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:27:23 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/23 20:26:02 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/map_utils.h"
#include "../../include/map/restrictions.h"

//TODO remove
#include <stdio.h>

t_answer	return_arr_from_line(char *line, int **arr)
{	
	int	str_len;
	int	i;
	int	converted;

	str_len = ft_strlen(line);
	*arr = malloc(sizeof(int) * (1 + str_len));
	if(*arr == NULL)
		return (ERROR);

	i = 0;
	while(i < str_len)
	{
		if(return_char2int_for_map(line[i], &converted) == NOT_FOUND)
			return (ERROR);
				
		(*arr)[i++] = converted;
	}
	(*arr)[i] = -1;
	return (SUCCESS);
}

t_answer	return_array_from_lines(t_list *lines, int lines_amount, int ***array)
{
	char	*line;
	int		*arr;
	int		i_line;

	*array = malloc(sizeof(int *) * (1 + (lines_amount)));
	if(*array == NULL)
		return (ERROR);
	
	i_line = 0;
	while (lines != NULL && (line = lines->content) != NULL)
	{
		lines = lines->next;

		arr = NULL;
		if(return_arr_from_line(line, &arr) == ERROR)
			return (ERROR);

		(*array)[i_line++] = arr;	
	}
	(*array)[i_line] = NULL;
	return (SUCCESS);
}

t_answer	handle_line(char *line, t_list **lines, t_parse_answer *is_map_started)
{
	t_answer answer;

	answer = ERROR;
	if(line == NULL)
		return (SUCCESS);
	
	if(is_a_map_line(line) == SUCCESS)
	{
		ft_lstadd_back(lines, ft_lstnew(ft_strdup(line)));
		*is_map_started = FOUND;
		answer = SUCCESS;
	}
	else if(*is_map_started == NOT_FOUND)
		answer = SUCCESS;
			
	free(line);
	return (answer);
}

t_answer	return_lines_from_file(char *file_name, t_list **lines)
{
	t_parse_answer	is_map_started;
	int				answer;
	char			*line;
	int				fd;

	is_map_started = NOT_FOUND;
	answer = 0;
	fd = open(file_name, 0);
	line = NULL;
	
	while((answer = get_next_line(fd, &line)) > 0)
		if(handle_line(line, lines, &is_map_started) == ERROR)
			return (ERROR);
	if(handle_line(line, lines, &is_map_started) == ERROR)
		return (ERROR);

	if (answer == -1)
		return (ERROR);

	close(fd);
	return (SUCCESS);
}

t_answer	return_map(char *file_name, t_map **map)
{
	t_list			*lines;
	int				**array;
	t_restriction	***restrictions;

	array = NULL;
	restrictions = NULL;

	*map = malloc(sizeof(**map));
	if(*map == NULL)
		return (ERROR);

	lines = NULL;
	if (return_lines_from_file(file_name, &lines) == ERROR)
	{
		ft_lstclear(&lines, free);
		return (ERROR);
	}
	
	if (return_array_from_lines(lines, ft_lstsize(lines), &array) == ERROR)
	{
		ft_lstclear(&lines, free);
		return (ERROR);
	}
	
	if(return_restrictions(array, &restrictions) == ERROR)
		return (ERROR);

	(*map)->array = array;
	(*map)->restrictions = restrictions;
	(*map)->scaled_to = 32;
	(*map)->minimap_ratio = 1;
	
	ft_lstclear(&lines, free);
	return (SUCCESS);
}
