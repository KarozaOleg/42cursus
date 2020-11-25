/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:11:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/24 21:42:02 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# include "../global_essences.h"

t_answer	handle_key(int keycode, int *pov_change, int *player_move);
t_answer	handle_key_close(int keycode);

#endif
