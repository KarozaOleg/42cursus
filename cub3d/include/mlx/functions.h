/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:14:10 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 17:50:18 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "../../include/mlx/essences.h"
# include "../../include/global.h"

t_answer	return_mlx(t_mlx_my **mlx_my);
void		free_mlx(t_mlx_my *mlx_my);
#endif