/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 00:41:50 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/10 22:29:31 by sgrindhe         ###   ########.fr       */
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

void			print_struct_values(tetrimino *tet)
{
	int n;

	n = 0;
	while (n < 4)
	{
		ft_putstr("point ");
		ft_putnbr(n);
		ft_putstr(" = ");
		ft_putnbr((*tet).points[n].x);
		ft_putstr(", ");
		ft_putnbr((*tet).points[n].y);
		ft_putchar('\n');
		n++;
	}
}

static void		shift_points(tetrimino *tet, int x_distance, int y_distance)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		(*tet).points[n].x += x_distance;
		(*tet).points[n].y += y_distance;
		n++;
	}
}

void			move_to_0_0(tetrimino **tets, int num_of_squares)
{
	tetrimino	*current;
	int			i;
	int			n;
	int			smallest_x_offset;
	int			smallest_y_offset;

	i = 0;
	while (i < num_of_squares)
	{
		smallest_x_offset = 3;
		smallest_y_offset = 3;
		current = tets[i];
		n = 0;
		while (n < 4)
		{
			if ((*current).points[n].x < smallest_x_offset)
				smallest_x_offset = (*current).points[n].x;
			if ((*current).points[n].y < smallest_y_offset)
				smallest_y_offset = (*current).points[n].y;
			n++;
		}
		ft_putendl("original:");
		print_struct_values(current);
		print_struct(current);
		shift_points(current, -smallest_x_offset, -smallest_y_offset);
		ft_putstr("modified: smallest x offset: ");
		ft_putnbr(smallest_x_offset);
		ft_putchar('\n');
		print_struct_values(current);
		print_struct(current);
		ft_putchar('\n');
		i++;
	}
}
