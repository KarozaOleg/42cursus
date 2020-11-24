/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:55:50 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/24 21:03:15 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/keys.h"

t_answer	handle_key(int keycode, int *pov_change, int *player_move)
{
	*pov_change = 0;
	*player_move = 0;
	if(keycode == 97 || keycode == 119 || keycode == 100 || keycode == 115)
	{
		if(keycode == 97)
		 	*pov_change = -1;
		else if(keycode == 100)
			*pov_change = 1;
		else if(keycode == 115)
			*player_move = -1;
		else if(keycode == 119)
			*player_move = 1;
		else
			return (ERROR);
		return (SUCCESS);
	}
	return (ERROR);
}

t_answer	handle_key_close(int keycode)
{
	if(keycode != 65307)
		return (ERROR);
	return SUCCESS;
}