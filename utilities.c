/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:45:46 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/01 03:58:46 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
tetrimino	*make_tetriminos(int quantity)
{
	int			i;
	int			n;
	tetrimino	*t_array;
	tetrimino	current;

	t_array = malloc(sizeof(tetrimino) * (quantity + 1));
	i = 0;
	n = 0;
	while (i < quantity)
	{
		current = malloc(sizeof(tetrimino));
		while (current.points[n])
		{
			current.points[n].x = 0;
			current.points[n].y = 0;
			n++;
		}
		t_array[i++] = current;
	}
	t_array[quantity] = NULL;
	return (t_array);
}
*/

tetrimino	*new_tetrimino()
{
	int			n;
	tetrimino	*result;

	result = malloc(sizeof(tetrimino));
	n = 0;
	while (n < 4)
	{
		(*result).points[n].x = 0;
		(*result).points[n].y = 0;
		n++;
	}
	return (result);
}

int			check_around_point(char **point, int x, int y)
{
	int		counter;

	counter = 0;
	if (x != 3 && point[x + 1][y] == '#')
		counter++;
	if (x != 0 && point[x - 1][y] == '#')
		counter++;
	if (y != 3 && point[x][y + 1] == '#')
		counter++;
	if (y != 0 && point[x][y - 1] == '#')
		counter++;
	return (counter);
}

int			count_connections(char **array)
{
	int		y;
	int		x;
	int		counter;

	counter = 0;
	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			if (array[x][y] == '#')
				counter += check_around_point(array, x, y);
			y++;
		}
		x++;
	}
	return (counter);
}

tetrimino	**convert_squares_struct_array(int fd)
{
	int				f;
	int				s;
	int				t;
	int				n;
	char			buffer;
	tetrimino		**t_array;


	f = 0;
	s = 0;
	t = -1;
	t_array = malloc(sizeof(*tetrimino) * (30 + 1));
	t_array[30] = NULL;
	//t_array = make_tetriminos(30);
	while (read(fd, &buffer, 1))
	{
		t++;
		if (t == 0 && s == 0)
			t_array[f] = new_tetrimino();
		if (t > 4)
			output_then_exit("bad file format");
		if ((buffer == '#' || buffer == '.') && buffer != '\n')
		{
			(*t_array[f]).points[n].x = t;
			(*t_array[f]).points[n].y = s;
			n++;
		}
		else if (buffer != '#' && buffer != '.' && buffer != '\n')
			output_then_exit("bad character");
		else if (buffer == '\n')
		{
			if (s == 4)
			{
				f++;
				s = 0;
				t = -1;
			}
			else
			{
				s++;
				t = -1;
			}
		}
	}
	return (t_array);
}
