/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:45:46 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/24 04:29:22 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

char		***new_3d_array(int	num_of_2d_arrays, int width, int height)
{
	int		i;
	char	***result;
	
	result = (char***)malloc(sizeof(char**) * (num_of_2d_arrays + 1));
	result[num_of_2d_arrays] = NULL;
	i = 0;
	while (result[i] != NULL)
	{
		result[i] = ft_2d_char_array(width, height);
		i++;
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

char		***convert_squares_to_3d_array(int fd)
{
	int				f;
	int				s;
	int				t;
	char			buffer;
	char			***array_3d;

	f = 0;
	s = 0;
	t = -1;
	array_3d = (char***)malloc(sizeof(char**) * 30);
	while (read(fd, &buffer, 1))
	{
		t++;
		if (s == 0 && t == 0)
			array_3d[f] = ft_2d_char_array(4, 4);
		if (t > 4)
			output_then_exit("bad file format");
		if ((buffer == '#' || buffer == '.') && buffer != '\n')
		{
			array_3d[f][s][t] = buffer;
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
