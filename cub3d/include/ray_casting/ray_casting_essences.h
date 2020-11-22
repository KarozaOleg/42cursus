/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_essences.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:29:24 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/22 14:58:25 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_ESSENCES_H
# define RAY_CASTING_ESSENCES_H

# include "../global_essences.h"

typedef struct	s_ray
{
	int		index;
	float	distance;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_hit_content;
	t_bool	was_hit_vertical;
	float	angle;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
}				t_ray;

typedef struct	s_ray_cast_var
{
	float xstep;
	float ystep;
	float xintercept;
	float yintercept;
}				t_ray_cast_var;

typedef	struct	s_ray_cast_result
{
	t_bool		wall_hit;
	float		wall_hit_x;
	float		wall_hit_y;
	int			wall_content;
}				t_ray_cast_result;
#endif