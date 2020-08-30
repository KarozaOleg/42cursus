/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:42:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 17:11:24 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.h"
#include "../include/parse/map.h"
#include "../include/parse/settings.h"
#include "../include/mlx/functions.h"


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