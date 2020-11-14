/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_essence.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:14:46 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/14 17:20:39 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_ESSENCES_H
# define TEXTURE_ESSENCES_H

typedef struct	s_image
{
	unsigned int	*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				endl;
}				t_image;

#endif