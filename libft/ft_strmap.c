/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 21:10:43 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 00:51:39 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	size_t	i;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	newstr = ft_strnew(size);
	if (newstr == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		newstr[i] = f(s[i]);
	}
	return (newstr);
}
