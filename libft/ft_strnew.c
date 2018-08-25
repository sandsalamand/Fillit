/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:18:12 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/11 02:23:12 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*newstr;

	newstr = (char*)malloc(size + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		newstr[i] = '\0';
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
