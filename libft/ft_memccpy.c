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
#include <stdio.h>

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
                return (++p); 
            break;
        }
    }
    return (NULL);
}

int main()
{
    char src[] = "test basic du memccpy !";
    char buff1[22];

    printf("%p\n", buff1);
    memset(buff1, 0, sizeof(buff1));    
    char *r2 = ft_memccpy(buff1, src, 'm', 22);

    printf("%c\n", r2);
}