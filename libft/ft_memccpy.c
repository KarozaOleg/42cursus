/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:18:55 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 10:18:55 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    size_t i;
    unsigned char *p;

    p = 0;
    i = 0;
    while (i < n)
    {
        if(((unsigned char *)src)[i] == (unsigned char)c)
        {
            if(i < n - 1)
                p = &((unsigned char *)dest)[i + 1];      
            break;
        }      
        ((unsigned char *)src)[i] = ((unsigned char *)dest)[i];
        ++i;
    }
    return (void *)p;
}

