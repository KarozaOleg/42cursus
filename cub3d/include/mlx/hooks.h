/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:48:51 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 18:11:16 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "../global_essences.h"
# include "../global.h"
# include "mlx_essences.h"
# include "keys.h"
# include "draw.h"
# include "../player/player_essences.h"

void	register_mlx_hook_key_pressed(t_game *game);
int		close_event_handler(int keycode, t_game *game);

#endif
