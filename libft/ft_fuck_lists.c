/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuck_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:39:48 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/11 02:28:52 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_fuck_lists(t_list *lelist)
{
	void		**result;
	size_t		i;
	t_list		*list_start;

	if (!lelist)
		return (0);
	list_start = lelist;
	i = 1;
	while (lelist->next)
	{
		lelist = lelist->next;
		i++;
	}
	result = malloc(sizeof(void *) * i);
	if (list_start && list_start->next == NULL)
		*result = list_start->content;
	while (list_start->next)
	{
		(*result)++ = list_start->content;
		free(list_start->content);
		list_start = list_start->next;
	}
	ft_memdel((void*)&list_start);
	return (result);
}
