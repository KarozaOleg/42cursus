/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:59:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/14 15:25:30 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *elem;

	elem = malloc(sizeof(t_list));
	if (elem != NULL)
	{
		(*elem).content = content;
		(*elem).next = NULL;
	}
	return (elem);
}
