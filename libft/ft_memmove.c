/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 01:32:14 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/04 23:25:41 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;

	i = 0;
	if (len == 0)
		return (dest);
	if ((unsigned char*)src < (unsigned char*)dest)
	{
		while (--len > 0)
			((unsigned char*)dest)[len] = ((unsigned char*)src)[len];
		((unsigned char*)dest)[len] = ((unsigned char*)src)[len];
	}
	else
	{
		while (i < len)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dest);
}
