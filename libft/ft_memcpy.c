/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:09:59 by marvin            #+#    #+#             */
/*   Updated: 2020/04/29 14:09:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;

    i = 0;
    while(i < n)
    {
        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
        ++i;
    }
    return dest;
}