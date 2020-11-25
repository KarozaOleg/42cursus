/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:16:07 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 21:13:48 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_UTILS_H
# define TEXTURE_UTILS_H

# include "../global.h"
# include "../global_essences.h"
# include "texture_essence.h"
# include "../map/map_essences.h"

int				return_texture_color(t_image *texture, int x, int y);
t_answer		return_texture_sprite(void *mlx, char *file_path_sprite,
t_image **texture_sprite);
t_answer		return_texture_wall(void *mlx, t_map_settings *map_settings,
t_image ***texture_wall);
void			free_texture_sprite(t_image *texture_sprite);
void			free_texture_walls(t_image **texture_wall);

#endif
