/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:08:38 by marvin            #+#    #+#             */
/*   Updated: 2020/04/29 14:08:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    size_t i;

    i = 0;
    while(i < n)
    {
        ((unsigned char *)s)[i] = 0;
        ++i;
    }
}