/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2d_int_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:49:32 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/08 21:43:10 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2d_int_array	*ft_map_2d_int_array(t_2d_int_array *t_2darray, int (*f)(int))
{
	t_2d_int_array	*newarray;
	unsigned int	i;
	unsigned int	z;

	i = 0;
	newarray = ft_2d_int_array(t_2darray->width, t_2darray->height);
	if (!newarray)
		return (NULL);
	while (i < t_2darray->width)
	{
		z = 0;
		while (z < t_2darray->height)
		{
			newarray->two_dim_array[i][z] = f(t_2darray->two_dim_array[i][z]);
			z++;
		}
		i++;
	}
	return (newarray);
}
