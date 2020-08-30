/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essences.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:33:13 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 17:54:57 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ESSENCES_H
# define ESSENCES_H

typedef struct	s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_img;

typedef struct	s_mlx_my
{ 
	void		*mlx;
	void		*mlx_win;
	t_mlx_img	*mlx_img;
	
}				t_mlx_my;

#endif