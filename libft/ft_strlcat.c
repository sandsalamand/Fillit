/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 20:33:50 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 23:00:25 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i] && i < size)
		i++;
	while ((src[k]) && ((i + k + 1) < size))
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i != size)
		dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
