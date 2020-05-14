/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:09:59 by marvin            #+#    #+#             */
/*   Updated: 2020/05/14 11:34:51 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	while (i < n)
	{
		p = &((unsigned char *)dest)[i];
		*p = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}
