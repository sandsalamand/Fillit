/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2d_char_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:15:00 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/29 01:45:37 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_map_2d_char_array(char **array, char (*f)(char))
{
	char			**result;
	unsigned int	i;
	unsigned int	z;

	i = 0;
	while (array[i])
		i++;
	z = 0;
	while (array[0][z])
		z++;
	result = ft_2d_char_array(i, z, '0');
	if (!result)
		return (NULL);
	i = 0;
	while (array[i] != NULL)
	{
		z = 0;
		while (array[i][z])
		{
			result[i][z] = f(array[i][z]);
			z++;
		}
		i++;
	}
	return (result);
}
