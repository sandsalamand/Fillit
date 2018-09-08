/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:45:46 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/08 00:52:20 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

tetrimino	**make_tetriminos(int quantity)
{
	int			i;
	int			n;
	tetrimino	**t_array;
	tetrimino	*current;

	t_array = malloc(sizeof(tetrimino) * (quantity + 1));
	i = 0;
	n = 0;
	while (i < quantity)
	{
		current = malloc(sizeof(tetrimino));
		n = 0;
		while (n < 4)
		{
			(*current).points[n].x = 0;
			(*current).points[n].y = 0;
			n++;
		}
		t_array[i++] = current;
	}
	t_array[quantity] = NULL;
	return (t_array);
}

static int		check_around_point(point *points, int n)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	while (i < 4)
	{
		if (i != n)
		{
			if (points[n].x + 1 == points[i].x)
				counter++;
			if (points[n].x - 1 == points[i].x)
				counter++;
			if (points[n].y + 1 == points[i].y)
				counter++;
			if (points[n].y - 1 == points[i].y)
				counter++;
		}
		i++;
	}
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
		while (n < 4)
		{
			counter = check_around_point((*arr[i]).points, n);
			n++;
		}
		i++;
	}
	if (counter == 6 || counter == 8)
		return (1);
	else
		return (0);
}

tetrimino		**convert_squares_to_struct_array(int fd, int num_of_squares)
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
			(*t_array[f]).points[n].x = t;
			(*t_array[f]).points[n++].y = s;
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
