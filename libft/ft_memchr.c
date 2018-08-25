/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:28:52 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/07/27 17:05:37 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char		*string;

	string = (unsigned const char*)s;
	while (n-- > 0)
	{
		if (*string == (unsigned char)c)
			return ((void*)string);
		string++;
	}
	return (NULL);
}
