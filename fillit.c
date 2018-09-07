/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 17:43:39 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/24 04:29:20 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

//yeahhhhhhhhhhhhhhhhhhhhhhhh
int		check_if_it_fits(char **array, char **square, int square_size)
{
	char	**copy;
	int		x;
	int		y;

	x = 0;
	copy = copy_2d_array(square, square_size, square_size);
	while (array[x])
	{
		print_2d_array(copy);
		y = 0;
		while (array[x][y])
		{
			if (copy[x][y] == '#')
			{
				free_2d_array(copy);
				return (0);
			}
			else if (copy[x][y] != array[x][y])
				copy[x][y] = array[x][y];
			y++;
		}
		x++;
	}
	free_2d_array(square);
	square = copy;
	return (1);
}

int		fillit(char ***array_3d)
{
	int		f;
	int		s;
	int		t;
	char	**square;
	int		square_size;

	f = 0;
	square_size = 4;
	square = ft_2d_char_array(square_size, square_size);
	fill_2d_array(square, '.');
	while (array_3d[f])
	{
		s = 0;
		//print_2d_array(array_3d[f]);
		if (count_connections(array_3d[f]) == 8
				|| count_connections(array_3d[f]) == 6)
		{
			while (array_3d[f][s])
			{
				t = 0;
				while (array_3d[f][s][t])
				{
					if (square[s][t] == '.')
					{
						if (check_if_it_fits(array_3d[f], square, square_size) == 0)
							square_size++;
					}
					t++;
				}
				s++;
			}
			f++;
		}
		else
			output_then_exit("invalid tetrimino");
		print_2d_array(square);
		square_size++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int			fd;

	if (argc != 2)
		output_then_exit("usage: fillit target_file");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		output_then_exit("error");
	fillit(convert_squares_to_3d_array(fd));
	return (0);
}
