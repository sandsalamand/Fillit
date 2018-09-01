/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:57:01 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/29 04:02:26 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					point;

typedef struct		s_tetrimino
{
	point			first;
	point			second;
	point			third;
	point			fourth;
}					tetrimino;

int			check_if_it_fits(char **array, char **square, int square_size);
int			check_around_point(char **point, int x, int y);
int			count_connections(char **array);
char		***convert_squares_to_3d_array(int fd);
char		**copy_2d_array(char **to_copy, int width, int height);
void		print_2d_array(char **array);
void		free_2d_array(char **to_free);
void		output_then_exit(char *str);
void		fill_2d_array(char **array, char c);

#endif
