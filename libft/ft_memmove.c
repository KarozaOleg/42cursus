/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:23:20 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 10:23:20 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   c;
    size_t          i;

    i = 0;
    c = ((unsigned char *)src)[i];
    while(i < n)
    {
        ((unsigned char *)dest)[i] = c;   
        ++i;         
        if(i < n)
            c = ((unsigned char *)src)[i];
    }
}