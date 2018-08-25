/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_char_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:37:00 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/24 03:00:25 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_2d_char_array(unsigned int width, unsigned int height)
{
	unsigned int		i;
	char				**result;

	if (width == 0 || height == 0)
		return (NULL);
	result = malloc(sizeof(char*) * (width + 1));
	result[width] = NULL;
	if (!result)
		return (NULL);
	i = 0;
	while (i < height)
	{
		result[i] = (char*)malloc(sizeof(char) * (height + 1));
		if (!result[i])
			return (NULL);
		result[i++][height] = '\0';
	}
	return (result);
}
