/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_essence.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:14:46 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/25 21:13:09 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_ESSENCE_H
# define TEXTURE_ESSENCE_H

typedef struct	s_image
{
	unsigned int	*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				endl;
}				t_image;

#endif
