/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:23:20 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/14 11:36:04 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	shift;
	size_t	i;

	shift = 0;
	if (dest > src && dest < (void*)(((unsigned char *)src) + n))
		shift = n - 1;
	i = 0 + shift;
	while (n-- > 0)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
		if (shift > 0)
			i -= i - --shift;
	}
	return (dest);
}
