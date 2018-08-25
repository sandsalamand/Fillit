/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 04:19:49 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/11 02:25:22 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;
	size_t			i;

	cast = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		cast[i] = c;
		i++;
	}
	return (s);
}
