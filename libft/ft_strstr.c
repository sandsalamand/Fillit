/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:41:45 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 00:33:17 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int counter;

	i = -1;
	if (to_find[0] == '\0')
		return (char*)(str);
	while (str[++i] != '\0')
	{
		counter = -1;
		while (to_find[++counter] != '\0')
		{
			if (to_find[counter] != str[i + counter])
				break ;
			if (to_find[counter + 1] == '\0')
				return (char*)(str + i);
		}
	}
	return (0);
}
