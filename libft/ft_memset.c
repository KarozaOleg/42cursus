/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:13:43 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 10:13:43 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)    
        ((unsigned char *)s)[i++] = (unsigned char)c;    
    return (s);
}