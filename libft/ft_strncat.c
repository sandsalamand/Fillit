/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 02:06:48 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 00:28:45 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		counter;

	if (n == 0)
		return (dest);
	i = ft_strlen(dest);
	counter = 0;
	while (src[counter] && n-- > 0)
	{
		dest[i] = src[counter];
		counter++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
