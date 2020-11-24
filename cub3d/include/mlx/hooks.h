/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:48:51 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/24 21:00:19 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "../global_essences.h"
# include "../global.h"
# include "mlx_essences.h"
# include "keys.h"

void	register_mlx_hook_key_pressed(t_game *game);

#endif
