/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:42:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 13:17:42 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.h"
#include "../include/map/map_utils.h"
#include "../include/mlx/mlx_utils.h"
#include "../include/settings/settings_utils.h"

void	ft_putstr(char *str)
{
	ft_putstr_fd(str, 0);
}

int		cub3d_exit(char *exit_comment, t_map_settings *settings, int **map, t_mlx_my *mlx_my)
{
	ft_putstr(exit_comment);
	if(ft_strlen(exit_comment) > 0)
		ft_putstr("\n");
	free_settings(settings);
	free_map(map);
	free_mlx(mlx_my);
	return (0);
}