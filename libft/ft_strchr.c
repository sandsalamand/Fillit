/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:44:42 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/07/29 21:35:48 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*c_s;

	c_s = (char *)s;
	while (*c_s)
	{
		if (*c_s == c)
			return (c_s);
		c_s++;
	}
	if (*c_s == c)
		return (c_s);
	return (NULL);
}
