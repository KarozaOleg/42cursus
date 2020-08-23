/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:27:23 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/23 14:54:01 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse/map.h"

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
		if(return_char2int_for_map(line[i], &converted) == ERROR)
			return (ERROR);
		(*arr)[i] = converted;
		++i;
	}
	(*arr)[i] = -1;
	return (SUCCESS);
}

t_answer	return_map_from_lines(t_list *lines, int lines_amount, int ***map)
{
	char	*line;
	int		*arr;
	int		i_line;

	*map = malloc(sizeof(int *) * (1 + lines_amount));
	if(*map == NULL)
		return (ERROR);
	
	i_line = 0;
	while (lines != NULL && (line = lines->content) != NULL)
	{
		lines = lines->next;

		arr = NULL;
		if(return_arr_from_line(line, &arr) == ERROR)
			return (ERROR);

		(*map)[i_line++] = arr;
	}
	(*map)[i_line] = NULL;
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

t_answer	return_map(char *file_name, int ***map)
{
	t_list	*lines;

	lines = NULL;
	if (return_lines_from_file(file_name, &lines) == ERROR)
	{
		ft_lstclear(&lines, free);
		return (ERROR);
	}
	
	if (return_map_from_lines(lines, ft_lstsize(lines), map) == ERROR)
	{
		ft_lstclear(&lines, free);
		return (ERROR);
	}
	
	ft_lstclear(&lines, free);
	return (SUCCESS);
}
