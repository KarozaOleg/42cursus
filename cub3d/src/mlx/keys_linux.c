/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:55:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 22:49:58 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/keys.h"

t_answer	handle_key(int keycode, int *pov_change, t_player_move *player_move)
{
	*pov_change = 0;
	*player_move = UNDEFINED;
	if (keycode == 97 || keycode == 113 || keycode == 119 || keycode == 101
	|| keycode == 100 || keycode == 115 || keycode == 65361 || keycode == 65363)
	{
		if (keycode == 97)
			*player_move = LEFT;
		else if (keycode == 113 || keycode == 65361)
			*pov_change = -1;
		else if (keycode == 119)
			*player_move = FRONT;
		else if (keycode == 101 || keycode == 65363)
			*pov_change = 1;
		else if (keycode == 100)
			*player_move = RIGHT;
		else if (keycode == 115)
			*player_move = BACK;
		else
			return (ERROR);
		return (SUCCESS);
	}
	return (ERROR);
}

t_answer	handle_key_close(int keycode)
{
	if (keycode != 65307)
		return (ERROR);
	return (SUCCESS);
}
