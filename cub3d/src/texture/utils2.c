/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:17:38 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 15:45:37 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/texture/texture_utils.h"

void		free_texture_sprite(t_image *texture_sprite)
{
	if (texture_sprite != NULL)
		free(texture_sprite);
}

void		free_texture_walls(t_image **texture_wall)
{
	int i;

	if (texture_wall == NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		free(texture_wall[i]);
		i += 1;
	}
	free(texture_wall);
}
