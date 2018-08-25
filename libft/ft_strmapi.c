/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 23:23:27 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 00:55:34 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*newstr;
	size_t		i;
	size_t		size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	newstr = ft_strnew(size);
	if (newstr == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		newstr[i] = f(i, s[i]);
	}
	return (newstr);
}
