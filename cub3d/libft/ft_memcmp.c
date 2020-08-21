/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:46:58 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/13 17:21:13 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		answer;
	size_t	i;

	answer = 0;
	i = 0;
	while (i < n)
	{
		answer = (int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		if (answer != 0)
			break ;
		++i;
	}
	return (answer);
}
