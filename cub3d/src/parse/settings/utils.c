/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:16:23 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/23 12:23:41 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse/settings.h"

void		free_settings(t_map_settings *settings)
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

t_answer is_settings_valid(t_map_settings *settings)
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
