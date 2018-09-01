/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_2d_arrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 02:11:54 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/30 01:16:27 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

void	output_then_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	fill_2d_array(char **array, char c)
{
	int x;
	int y;

	x = 0;
	while (array[x] != NULL)
	{
		ft_putnbr(x);
		ft_putchar('\n');
		/*if I add x = 0 here it starts an infinite loop
		obviously but it also makes the condition true somehow.*/
		y = 0;
		if (array[x][0])
			ft_putendl("what the fuck");
		//I would prefer to not have to use this way
		while (y < 4)
		{
			ft_putendl("arr");
			array[x][y] = c;
			y++;
		}
		x++;
	}
	print_2d_array(array);
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
		ft_memdel((void**)to_free[i++]);
	ft_memdel((void**)to_free);
}
