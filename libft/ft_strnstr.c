/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:57:34 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 00:52:16 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t i;
	size_t counter;

	i = -1;
	if (to_find[0] == '\0')
		return (char*)(str);
	while (str[++i] != '\0')
	{
		counter = -1;
		while (to_find[++counter] != '\0')
		{
			if ((i + counter) >= len)
				break ;
			if (to_find[counter] != str[i + counter])
				break ;
			if (to_find[counter + 1] == '\0')
				return (char*)(str + i);
		}
	}
	return (0);
}
