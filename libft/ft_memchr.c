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

void *memchr(const void *s, int c, size_t n)
{
    void *p;
    size_t i;

    p = 0;
    i = 0;
    while(i < n)
    {
        if(((unsigned char *)s)[i] != (unsigned char)c)
        {
            ++i;
            continue;
        }
        p = &((unsigned char *)s)[i];
        break;
    }
    return p;
}