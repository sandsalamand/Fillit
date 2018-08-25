/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_int_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:07:22 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/08 21:45:51 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2d_int_array		*ft_2d_int_array(unsigned int width, unsigned int height)
{
	unsigned int		i;
	int					**temp_array;
	t_2d_int_array		*s_result;

	if (width == 0 || height == 0)
		return (NULL);
	temp_array = malloc(sizeof(int*) * width);
	if (!temp_array)
		return (NULL);
	i = 0;
	while (i < height)
	{
		temp_array[i++] = (int*)malloc(sizeof(int) * height);
	}
	s_result = malloc((sizeof(int*) * width) * (sizeof(int) * height));
	s_result->two_dim_array = temp_array;
	s_result->width = width;
	s_result->height = height;
	return (s_result);
}
