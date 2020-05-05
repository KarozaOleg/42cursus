/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:00:03 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/05 15:00:03 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int strncmp(const char *s1, const char *s2, size_t n)
{
    int answer;
    size_t i;

    answer = 0;
     i = 0;
    while(i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        answer = s1[i] - s2[i];
        if(answer != 0)
            break;
        ++i;
    }
    return (answer);
}