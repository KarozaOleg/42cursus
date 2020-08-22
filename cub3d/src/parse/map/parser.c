/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:27:23 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/22 17:32:53 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse/map.h"

int	return_integer_arr_from_line(char *line, int **arr)
{	
	int str_len;
	int i;

	str_len = ft_strlen(line);
	*arr = malloc(sizeof(int) * (1 + str_len));
	if(*arr == NULL)	
		return (-1);

	i = 0;
	while(i < str_len)	
	{
		(*arr)[i] = line[i] - 48;
		++i;
	}	
	(*arr)[i] = -1;
	return (0);
}

int return_map_from_lines(t_list *lines, int lines_amount, int ***map)
{
	char	*line;
	int		*arr;
	int		i_line;

	*map = malloc(sizeof(int *) * (1 + lines_amount));
	if(*map == NULL)
		return (-1);	
	
	i_line = 0;
	while (lines != NULL && (line = lines->content) != NULL)
	{
		lines = lines->next;		

		arr = NULL;
		if(return_integer_arr_from_line(line, &arr) < 0)
			return (-1);

		(*map)[i_line++] = arr;
	}
	(*map)[i_line] = NULL;
	return (0);
}

int	return_lines_from_file(char *file_name, t_list **lines)
{
	int		answer;
	char	*line;
	int		fd;

	answer = 0;
	fd = open(file_name, 0);
	line = NULL;
	
	while((answer = get_next_line(fd, &line)) > 0)
	{		
		ft_lstadd_back(lines, ft_lstnew(ft_strdup(line)));
		free(line);
	}

	if(line != NULL)
	{
		ft_lstadd_back(lines, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	line = NULL;
	
	if (answer == -1)
		return (-1);
			
	close(fd);
	return (0);
}

int	return_map(char *file_name, int ***map)
{
	t_list	*lines;

	lines = NULL;
	if (return_lines_from_file(file_name, &lines) < 0)
	{
		ft_lstclear(&lines, free);
		return (-1);
	}
	
	if (return_map_from_lines(lines, ft_lstsize(lines), map) < 0)
	{
		ft_lstclear(&lines, free);
		//TODO free map
		return (-1);
	}
	ft_lstclear(&lines, free);
	return (0);
}

void	free_map(int** map)
{
	int i;

	if(map == NULL)
		return ;
		
	i = 0;
	while(map[i] != NULL)
		free(map[i++]);
	free(map);	
}