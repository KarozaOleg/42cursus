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
    unsigned char   *p;
    size_t          i;
    
    p = NULL;
    i = 0;
    while (i < n)
    {
        p = &((unsigned char *)dest)[i];
        *p = ((unsigned char *)src)[i];        
        ++i;
        if (*p == (unsigned char)c)
        {
            if(i < n)
                return ((void *)(p++)); 
            break;
        }
    }
    return (NULL);
}