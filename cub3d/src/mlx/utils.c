/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:54:24 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 18:00:51 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/functions.h"
#include <stdio.h>
void	free_mlx(t_mlx_my *mlx_my)
{
	if(mlx_my == NULL)
		return ;
		
	if(mlx_my->mlx_win != NULL)
		mlx_destroy_window(mlx_my->mlx, mlx_my->mlx_win);
	
	if(mlx_my->mlx != NULL)
		free(mlx_my->mlx);
	
	free(mlx_my);
}