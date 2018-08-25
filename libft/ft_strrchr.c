/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 18:59:47 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/07/29 21:35:57 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*c_s;
	char	*last_ptr;

	c_s = (char *)s;
	last_ptr = NULL;
	while (*c_s)
	{
		if (*c_s == c)
			last_ptr = c_s;
		c_s++;
	}
	if (*c_s == c)
		return (c_s);
	return (last_ptr);
}
