/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:02:07 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 13:02:07 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   *p;
    size_t          i;

    p = NULL;
    i = 0;
    while (i < n)
    {        
        p = &((unsigned char *)s)[i];
        if (*p == (unsigned char)c)
            return (p);
        ++i;
    }
    return (NULL);
}