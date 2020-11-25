/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_macos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:55:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 22:23:09 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx/keys.h"

t_answer	handle_key(int keycode, int *pov_change, int *player_move)
{
	*pov_change = 0;
	*player_move = 0;
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		if (keycode == 0)
			*pov_change = -1;
		else if (keycode == 2)
			*pov_change = 1;
		else if (keycode == 1)
			*player_move = -1;
		else if (keycode == 13)
			*player_move = 1;
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
