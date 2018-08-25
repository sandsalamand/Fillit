/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:40:42 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/08 21:44:15 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *orig_copy;
	t_list *temp_list;

	orig_copy = (*alst)->next;
	while (orig_copy)
	{
		temp_list = orig_copy->next;
		ft_lstdelone(&orig_copy, del);
		orig_copy = temp_list;
	}
	ft_lstdelone(alst, del);
}
