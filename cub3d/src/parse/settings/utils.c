/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:16:23 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 16:11:10 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse/settings.h"

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

t_answer		is_settings_valid(t_map_settings *settings)
{
	if(settings == NULL)
		return (ERROR);
	if(settings->resolution == NULL)
		return (ERROR);
	if(settings->texture_no == NULL)
		return (ERROR);
	if(settings->texture_so == NULL)
		return (ERROR);
	if(settings->texture_we == NULL)
		return (ERROR);
	if(settings->texture_ea == NULL)
		return (ERROR);
	if(settings->texture_s == NULL)
		return (ERROR);
	if(settings->color_floor == NULL)
		return (ERROR);
	if(settings->color_ceiling == NULL)
		return (ERROR);

	return (SUCCESS);
}

void			initialize_settings(t_map_settings *settings)
{
	settings->resolution = NULL;
	settings->texture_no = NULL;
	settings->texture_so = NULL;
	settings->texture_we = NULL;
	settings->texture_ea = NULL;
	settings->texture_s = NULL;
	settings->color_floor = NULL;
	settings->color_ceiling = NULL;
}

void			free_settings(t_map_settings *settings)
{
	if(settings == NULL)
		return ;
		
	if(settings->resolution != NULL)
		free(settings->resolution);

	if(settings->texture_no != NULL)
		free(settings->texture_no);

	if(settings->texture_so != NULL)
		free(settings->texture_so);

	if(settings->texture_we != NULL)
		free(settings->texture_we);

	if(settings->texture_ea != NULL)
		free(settings->texture_ea);

	if(settings->texture_s != NULL)
		free(settings->texture_s);

	if(settings->color_floor != NULL)
		free(settings->color_floor);

	if(settings->color_ceiling != NULL)
		free(settings->color_ceiling);

	free(settings);
}