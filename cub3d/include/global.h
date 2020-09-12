/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:08:44 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/12 11:46:18 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
#define PI 3.14159265358979323846

# include "../libft/libft.h"
# include "game/game_essences.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

void	ft_putstr(char *str);
int		cub3d_exit(char *exit_comment, t_game *game);

#endif