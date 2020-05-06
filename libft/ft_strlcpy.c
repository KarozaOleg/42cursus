/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:53:57 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 13:53:57 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    if(*dst == '\0' || *src == '\0')
        return (0);

    i = 0;
    while (i < size - 1 && src[i] != '\0')
    {
        dst[i] = src[i];
        ++i;
    }    
    dst[i] = '\0';
    while (src[i] != '\0')
        ++i;
    return (i);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Hello is here\n");
    char *dest = malloc(15 * sizeof(char));
    size_t answer = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
    printf("answer: %d\n", answer);
    return 0;
}