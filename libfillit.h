/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:57:01 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/01 03:58:51 by sgrindhe         ###   ########.fr       */
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
	point			points[4];
}					tetrimino;

unsigned int	check_file_for_squares(int fd);
static int	check_around_point(point *points, int n);
int		count_connections(char **array);
tetrimino	**convert_squares_to_struct_array(int fd);
char		**copy_2d_array(char **to_copy, int width, int height);
void		print_2d_array(char **array);
void		free_2d_array(char **to_free);
void		output_then_exit(char *str);
void		fill_2d_array(char **array, char c);

#endif
