/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_2d_arrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 02:11:54 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/13 00:59:35 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

void	output_then_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	print_2d_array(char **array)
{
	int i;
	int z;

	i = 0;
	while (array[i])
	{
		z = 0;
		while (array[i][z])
			ft_putchar(array[i][z++]);
		ft_putchar('\n');
		i++;
	}
}

char	**copy_2d_array(char **to_copy, int width, int height)
{
	char	**result;
	int		i;
	int		z;

	result = ft_2d_char_array(width, height, '0');
	i = 0;
	while (result[i])
	{
		z = 0;
		while (result[i][z])
		{
			result[i][z] = to_copy[i][z];
			z++;
		}
		i++;
	}
	return (result);
}

void	free_2d_array(char **to_free)
{
	int i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
}
