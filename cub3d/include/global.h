/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:08:44 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 13:02:46 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "../libft/libft.h"
# include "map/map_essences.h"
# include "mlx/mlx_essences.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

typedef enum	s_answer
{
	SUCCESS,
	ERROR
}				t_answer;

void	ft_putstr(char *str);
int		cub3d_exit(char *exit_comment, t_map_settings *settings, int **map, t_mlx_my *mlx_my);

#endif