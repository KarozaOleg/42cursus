/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:13:07 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/05 14:13:07 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dest;

    dest = malloc((len + 1) * sizeof(char));
    if(dest != NULL)
        ft_strlcpy(dest, &s[start], len + 1);
    return (dest);
}