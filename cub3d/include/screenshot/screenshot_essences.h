/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_essences.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:51:44 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/24 21:48:55 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREENSHOT_ESSENCES_H
# define SCREENSHOT_ESSENCES_H

typedef struct	s_screenshot
{
	char	signature[2];
	int		filesize;
	int		reserved;
	int		offset;
	int		header_size;
	int		dimension[2];
	short	planes;
	short	bpp;
	int		compression;
	int		size;
	int		resolution[2];
	int		pltcolor;
	int		impcolor;
}				t_screenshot;

#endif
