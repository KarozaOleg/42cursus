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

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char c;

    i = 0;
    c = ((unsigned char *)src)[i];
    while(i < n)
    {
         ((unsigned char *)dest)[i] = c;
            
        if(i < n - 1)
            c = ((unsigned char *)src)[i + 1];
        ++i;
    }
}