/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:14:34 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 14:14:34 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
    while (dst[i] != '\0')    
        i++;    
    return (i + ft_strlcpy(&dst[i], src, size));
}