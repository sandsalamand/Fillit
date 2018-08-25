/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:53:10 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/09 20:29:58 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	newlist = ft_memalloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = 0;
	newlist->content_size = 0;
	newlist->next = NULL;
	if (content)
	{
		newlist->content = ft_memalloc(content_size);
		if (!newlist->content)
		{
			ft_memdel((void*)&newlist);
			return (NULL);
		}
		ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	return (newlist);
}
