/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:16:23 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/15 15:06:58 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/settings/settings_utils.h"

t_parse_answer	is_a_settings_line(char *line)
{	
	if (ft_memcmp(line,  "R", ft_strlen("R")) == 0)
		return (FOUND);
	if (ft_memcmp(line,  "NO", ft_strlen("NO")) == 0)
		return (FOUND);
	if (ft_memcmp(line,  "SO", ft_strlen("SO")) == 0)
		return (FOUND);
	if (ft_memcmp(line,  "WE", ft_strlen("WE")) == 0)
		return (FOUND);
	if (ft_memcmp(line,  "EA", ft_strlen("EA")) == 0)
		return (FOUND);
	if (ft_memcmp(line,  "S", ft_strlen("S")) == 0)
		return (FOUND);
	if (ft_memcmp(line,  "F", ft_strlen("F")) == 0)
		return (FOUND);
	if (ft_memcmp(line,  "C", ft_strlen("C")) == 0)
		return (FOUND);
	
	return (NOT_FOUND);
}

t_answer		is_map_settings_valid(t_map_settings *map_settings)
{
	if(map_settings == NULL)
		return (ERROR);
	if(map_settings->resolution == NULL)
		return (ERROR);
	if(map_settings->texture_no == NULL)
		return (ERROR);
	if(map_settings->texture_so == NULL)
		return (ERROR);
	if(map_settings->texture_we == NULL)
		return (ERROR);
	if(map_settings->texture_ea == NULL)
		return (ERROR);
	if(map_settings->texture_s == NULL)
		return (ERROR);
	if(map_settings->color_floor == NULL)
		return (ERROR);
	if(map_settings->color_ceiling == NULL)
		return (ERROR);

	return (SUCCESS);
}

void			initialize_map_settings(t_map_settings *map_settings)
{
	map_settings->resolution = NULL;
	map_settings->texture_no = NULL;
	map_settings->texture_so = NULL;
	map_settings->texture_we = NULL;
	map_settings->texture_ea = NULL;
	map_settings->texture_s = NULL;
	map_settings->color_floor = NULL;
	map_settings->color_ceiling = NULL;
}

void			free_map_settings(t_map_settings *map_settings)
{
	if(map_settings == NULL)
		return ;
		
	if(map_settings->resolution != NULL)
		free(map_settings->resolution);

	if(map_settings->texture_no != NULL)
		free(map_settings->texture_no);

	if(map_settings->texture_so != NULL)
		free(map_settings->texture_so);

	if(map_settings->texture_we != NULL)
		free(map_settings->texture_we);

	if(map_settings->texture_ea != NULL)
		free(map_settings->texture_ea);

	if(map_settings->texture_s != NULL)
		free(map_settings->texture_s);

	if(map_settings->color_floor != NULL)
		free(map_settings->color_floor);

	if(map_settings->color_ceiling != NULL)
		free(map_settings->color_ceiling);

	free(map_settings);
}