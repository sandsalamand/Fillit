/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 17:43:39 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/13 00:59:44 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int		check_if_it_fits(char **array, char **square, int square_size)
{
	char		**copy;
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

int		try_place_tetrimino(tetrimino *tet, char **square, point p, int sq_size)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		if ((*tet).points[n].y > sq_size || (*tet).points[n].x > sq_size
			|| square[(*tet).points[n].y + p.y][(*tet).points[n].x + p.x] == '#')
			return (0);
		n++;
	}
	return (1);
}

void	place_tetrimino(tetrimino *tet, char **square, int x, int y)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		square[(*tet).points[n].y + y][(*tet).points[n].x + x] = '#';
		n++;
	}
}

int		fillit(tetrimino **tets, int num_of_squares)
{
	int		f;
	point	p;
	char	**square;
	int		square_size;

	f = num_of_squares - 1;
	p.x = 0;
	square_size = 4;
	while (f >= 0)
	{
		square = ft_2d_char_array(square_size, square_size, '.');
		p.y = 0;
		while (p.y < square_size)
		{
			p.x = 0;
			while (p.x < square_size)
			{
				if (try_place_tetrimino(tets[f], square, p, square_size) == 1)
				{
					place_tetrimino(tets[f], square, p.x, p.y);
					print_2d_array(square);
					f--;
				}
				p.x++;
			}
			p.y++;
		}
		print_2d_array(square);
		free_2d_array(square);
		square_size++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int			fd;
	tetrimino	**temp;
	int			num_of_squares;

	if (argc != 2)
		output_then_exit("usage: fillit target_file");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		output_then_exit("error");
	num_of_squares = check_file_for_squares(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	temp = convert_squares_to_struct_array(fd, num_of_squares);
	/* this is broken, need to fix eventually
	if (count_connections(temp) == 0)
		output_then_exit("invalid tetrimino");
	*/
	move_to_0_0(temp, num_of_squares);
	fillit(temp, num_of_squares);
	return (0);
}
