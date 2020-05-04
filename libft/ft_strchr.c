/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:23:33 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 14:23:33 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *str;
    size_t i;

    str = (char *)s;
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != (unsigned char)c)
        {
            ++i;
            continue;
        }
        return &str[i];
    }
    return 0;
}