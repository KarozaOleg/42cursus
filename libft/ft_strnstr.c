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

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    char    *p;
    size_t  iBig;
    size_t  iLittle;

    p = NULL;
    iBig = 0;
    iLittle = 0;
    while (iBig < len && big[iBig] != '\0' && little[iLittle] != '\0')
    {        
        if (big[iBig] != little[iLittle])   
        {     
            p = NULL;    
            iLittle = 0;
        }     
        else 
        {
            if (p == NULL)
                p = &big[iBig];
            ++iLittle;
        }
        ++iBig;
    }
    if (big[iBig] == '\0' && little[iLittle] != '\0')
        p = NULL;
    return (p);
}