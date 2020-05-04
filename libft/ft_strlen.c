/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:51:58 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 13:51:58 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while(s[len] != '\0')
    {
        ++len;
    }
    return len;
}