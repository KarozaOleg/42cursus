/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:09:15 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/05 14:09:15 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strrchr(const char *s, int c)
{
    char *p;
    size_t i;

    p = NULL;
    i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == (char)c)
        {
            p = &s[i];
            break;
        }
        ++i;
    }
    return (p);
}