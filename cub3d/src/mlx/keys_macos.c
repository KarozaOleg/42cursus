/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_macos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:55:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 18:10:49 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx/keys.h"

t_answer	handle_key(int keycode, int *pov_change, t_player_move *player_move)
{
	*pov_change = 0;
	*player_move = UNDEFINED;
	if ((keycode >= 0 && keycode <= 2) || (keycode >= 12 && keycode <= 14) ||
(keycode >= 123 && keycode <= 124))
	{
		if (keycode == 0)
			*player_move = LEFT;
		else if (keycode == 2)
			*player_move = RIGHT;
		else if (keycode == 1)
			*player_move = BACK;
		else if (keycode == 13)
			*player_move = FRONT;
		else if (keycode == 12 || keycode == 123)
			*pov_change = -1;
		else if (keycode == 14 || keycode == 124)
			*pov_change = 1;
		else
			return (ERROR);
		return (SUCCESS);
	}
	return (ERROR);
}

t_answer	handle_key_close(int keycode)
{
	if (keycode != 53)
		return (ERROR);
	return (SUCCESS);
}
