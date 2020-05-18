/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:13:07 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/18 17:44:18 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	dest = malloc((len + 1) * sizeof(char));
	if (dest != NULL)
		ft_strlcpy(dest, &s[start], (len + 1));
	return (dest);
}
