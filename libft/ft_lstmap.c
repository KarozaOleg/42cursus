/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:45:43 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/14 22:28:43 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *elem;
	t_list *lst_new;
	t_list *current;

	if (lst == NULL || f == NULL || *f == NULL || del == NULL)
		return (NULL);	
	lst_new = NULL;
	current = NULL;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (elem == NULL)
		{
			ft_lstclear(&lst_new, del);
			break;
		}
		if (lst_new == NULL)
			lst_new = elem;
		if (current != NULL)
			current->next = elem;
		current = elem;
		lst = lst->next;
	}
	return (lst_new);
}
