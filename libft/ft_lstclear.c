/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:32:17 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/14 15:41:38 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *last;

	if (lst == NULL || del == NULL)
		return ;
	while ((last = ft_lstlast(*lst)))
		ft_lstdelone(last, del);
	lst = NULL;
}
