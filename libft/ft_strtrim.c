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
#include <stdio.h>

char *ft_strtrim(const char *s1, const char *set)
{
    char *dest;
    char *s1_start;
    int len_s1;
    int len_set;
    int len_dest;

    len_s1 = ft_strlen(s1);
    len_dest = len_s1;
    len_set = ft_strlen(set);

    printf("set_len:%d\n", len_set);

    s1_start = ft_strnstr(s1, set, len_set);
    printf("s1_start:%s\n", s1_start);
    if(s1_start != NULL)
    {
        len_dest -= len_set;
        s1_start += len_set;
    }
    else
        s1_start = (char*)s1;

    if(ft_strnstr(&s1[len_s1 - len_set], set, len_set) != NULL)
        len_dest -= len_set;

    dest = malloc((len_dest + 1) * sizeof(char));
    if(dest != NULL)
        ft_strlcpy(dest, s1_start, len_dest + 1);
    return (dest);
}

int main()
{
    char str[] = " TEST ";

    char *copy = ft_strtrim(str, " ");
    printf("%s\n", copy);
    return 0;
}