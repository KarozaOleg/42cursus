/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:13:07 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/05 14:13:07 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    char *dest;
    int len_s1;
    int len_s2;

	if(s1 == NULL || s2 == NULL)
		return (NULL);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    dest = malloc((len_s1 + len_s2 + 1) * sizeof(char));
    if(dest != NULL)
    {
        ft_memmove(dest, s1, len_s1);
        ft_strlcpy(&dest[len_s1], s2, len_s2 + 1);
    }
    return (dest);
}