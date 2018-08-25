/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:27:09 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 00:30:37 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		max;
	size_t		i;
	size_t		z;

	if (!s)
		return (0);
	i = (size_t)start - 1;
	z = 0;
	max = i + 1 + len;
	substr = ft_strnew(len);
	if (!substr)
		return (0);
	while (++i < max)
		substr[z++] = s[i];
	substr[z] = '\0';
	return (substr);
}
