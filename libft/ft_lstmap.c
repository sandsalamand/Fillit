/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 00:38:02 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/08 00:41:11 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list				*listptr;
	t_list				*result;

	if (!lst)
		return (0);
	listptr = f(lst);
	result = listptr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(listptr->next = f(lst)))
		{
			free(listptr->next);
			return (0);
		}
		listptr = listptr->next;
	}
	return (result);
}
