/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 00:41:50 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/08 00:41:59 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

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

int				point_cmp(point p1, point p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return (1);
	else
		return (0);
}

void			print_struct(tetrimino *tet)
{
	point	p;
	int		n;

	n = 0;
	p.y = 0;
	while (p.y < 4)
	{
		p.x = 0;
		if (point_cmp(p, (*tet).points[n]) == 1)
			ft_putchar('#');
		while (p.x < 4)
		{
			n = 0;
			while (n < 4)
			{
				if (point_cmp(p, (*tet).points[n]) == 1)
				{
					ft_putchar('#');
					break ;
				}
				n++;
			}
			if (n == 4)
				ft_putchar('0');
			p.x++;
		}
		ft_putchar('\n');
		p.y++;
	}
}

static void		shift_points_left(tetrimino *tet, int distance)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		(*tet).points[n].x -= distance;
		n++;
	}
}

void			move_to_0_0(tetrimino **tets, int num_of_squares)
{
	tetrimino	*current;
	int			i;
	int			n;
	int			smallest_offset;

	i = 0;
	smallest_offset = 3;
	while (i < num_of_squares)
	{
		current = tets[i];
		n = 0;
		while (n < 4)
		{
			if ((*current).points[n].x < smallest_offset)
				smallest_offset = (*current).points[n].x;
			n++;
		}
		print_struct(current);
		shift_points_left(current, smallest_offset);
		ft_putchar('\n');
		print_struct(current);
		i++;
	}
}
