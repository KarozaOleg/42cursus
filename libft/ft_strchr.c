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

char *ft_strchr(const char *s, int c)
{
    char *p;
    size_t i;

    p = 0;
    i = 0;
    while(s[i] != '\0')
    {
        if(s[i] != (unsigned char)c)
        {
            ++i;
            continue;
        }
        p = &s[i];
        break;
    }
    return p;
}