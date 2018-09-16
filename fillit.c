/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 17:43:39 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/13 22:43:50 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int		try_place_tetrimino(tetrimino *tet, char **square, point p, int sq_size)
{
	int		n;

	n = 0;
	sq_size -= 1;
	while (n < 4)
	{
		if ((*tet).points[n].y + p.y > sq_size || (*tet).points[n].x + p.x > sq_size
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
		free(square);
		ft_putendl("HEY");
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
	/*if (count_connections(temp, num_of_squares) != 1)
		output_then_exit("invalid tetrimino");*/
	move_to_0_0(temp, num_of_squares);
	fillit(temp, num_of_squares);
	return (0);
}
