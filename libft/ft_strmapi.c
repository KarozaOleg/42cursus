/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:00:03 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/13 15:09:25 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    int len;
    char *dest;
    unsigned int i;

	if(s == NULL || f == NULL)
		return (NULL);
    len = ft_strlen(s);
    dest = malloc(len + 1 * sizeof(char));
    if(dest != NULL)
    {
        i = 0;
        while(s[i])
        {
            dest[i] = f(i, s[i]);
            /*if(s[i] == '\0')
                break;*/
            ++i;
        }
        dest[i] = '\0';
    }
    return (dest);
}