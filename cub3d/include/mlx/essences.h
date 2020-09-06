/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essences.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:33:13 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/05 14:45:20 by mgaston          ###   ########.fr       */
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
	void		*win;
	t_mlx_img	*scene;
	
}				t_mlx_my;

#endif