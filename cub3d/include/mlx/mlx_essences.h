/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_essences.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:33:13 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/28 13:33:07 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_ESSENCES_H
# define MLX_ESSENCES_H

typedef struct	s_wall_spec
{
	int wall_top;
	int wall_bottom;
	int wall_height;
}				t_wall_spec;

typedef struct	s_rgb
{
	int	red;
	int green;
	int blue;
}				t_rgb;

typedef struct	s_resolution
{
	int	width;
	int height;
}				t_resolution;

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
