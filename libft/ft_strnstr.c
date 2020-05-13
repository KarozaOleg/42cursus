/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:13:07 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/13 18:04:17 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*p;
	size_t	i_big;
	size_t	i_little;

	p = (void *)big;
	i_big = 0;
	i_little = 0;
	while (i_big < len && big[i_big] != '\0' && little[i_little] != '\0')
	{
		if (big[i_big] != little[i_little])
		{
			p = NULL;
			i_little = 0;
		}
		else
		{
			if (p == NULL)
				p = (char *)&big[i_big];
			++i_little;
		}
		++i_big;
	}
	if (little[i_little] != '\0')
		p = NULL;
	return (p);
}
