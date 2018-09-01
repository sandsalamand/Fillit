/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:45:46 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/29 04:06:38 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

tetrimino	*make_tetriminos(int quantity)
{
	int			i;
	tetrimino	*t_array;
	tetrimino	current;

	t_array = malloc(sizeof(tetrimino) * (quantity + 1));
	i = 0;
	while (i < quantity)
	{
		current = malloc(sizeof(tetrimino));
		current.first.x = 0;
		current.first.y = 0;
		current.second.x = 0;
		current.second.y = 0;
		current.third.x = 0;
		current.third.y = 0;
		current.fourth.x = 0;
		current.fourth.y = 0;
		t_array[i++] = current;
	}
	t_array[quantity] = NULL;
	return (t_array);
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

tetrimino	*convert_squares_to_3d_array(int fd)
{
	int				f;
	int				s;
	int				t;
	char			buffer;
	tetrimino		*t_array;


	f = 0;
	s = 0;
	t = -1;
	t_array = make_tetriminos(30);
	while (read(fd, &buffer, 1))
	{
		t++;
		if (s == 0 && t == 0)
			array_3d[f] = ft_2d_char_array(4, 4, '0');
		if (t > 4)
			output_then_exit("bad file format");
		if ((buffer == '#' || buffer == '.') && buffer != '\n')
		{
			t_array[t].first.x = t;
			t_array[t].first.y = s;
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
				array_3d[f][s][t] = '\0';
				s++;
				t = -1;
			}
		}
	}
	return (array_3d);
}
