/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:45:46 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/05 03:09:57 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

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

unsigned int	check_file_for_squares(int fd)
{
	int				newline;
	int				count_lines;
	int				size;
	char			buffer;

	newline = 0;
	size = 0;
	count_lines = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (newline > 0)
			newline --;
		if (buffer == '\n' && newline == 0)
		{
				if (count_lines != 4)
					output_then_exit("bad file format");
				count_lines = 0;
				newline = 2;
				size++;
		}
		else if (buffer == '#' || buffer == '.')
			count_lines++;
		else if (buffer != '\n')
			output_then_exit("bad file format");
	}
	return (size);
}
/*
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
*/

int			check_around_point(point *points, int x, int y)
{
	int		counter;

	counter = 0;
	if (points[n].x != 3 && point[x + 1][y] == '#')
		counter++;
	if (x != 0 && point[x - 1][y] == '#')
		counter++;
	if (y != 3 && point[x][y + 1] == '#')
		counter++;
	if (y != 0 && point[x][y - 1] == '#')
		counter++;
	return (counter);
}

int			count_connections(tetrimino **arr)
{
	int		i;
	int		n;
	int		counter;
	
	counter = 0;
	i = 0;
	while (arr[i])
	{
		n = 0;
		while (points[n])
		{
			if (arr[i].points[n].x != 3 && arr.points[n].x + 1
				== arr.points[n + 1].x)
				counter++;
			if (arr[i].points[n].x != 0 && arr.points[n].x - 1
				== arr.points[n + 1].x)
				counter++;
			//switch these to this ^ format
			if (y != 3 && point[x][y + 1] == '#')
				counter++;
			if (y != 0 && point[x][y - 1] == '#')
				counter++;
		//	counter += check_around_point(array, x, y);
		}
		i++;
	}
	if (counter == 6 || counter == 8)
		return (1);
	else
		return (0);
}

tetrimino	**convert_squares_to_struct_array(int fd, int num_of_squres)
{
	int				f;
	int				s;
	int				t;
	int				n;
	char				buffer;
	tetrimino			**t_array;


	f = 0;
	s = 0;
	t = -1;
	n = 0;
	t_array = make_tetriminos((num_of_squares));
	while (read(fd, &buffer, 1))
	{
		t++;
		if (buffer == '#')
		{
			if (n >= 3)
				output_then_exit("bad tetrimino format");
			(*t_array[f]).points[n].x = t;
			(*t_array[f]).points[n].y = s;
			n++;
		}
		else if (buffer == '\n')
		{
			if (s == 4)
			{
				f++;
				n = 0;
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
