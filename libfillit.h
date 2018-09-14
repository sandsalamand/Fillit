/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:57:01 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/09/13 22:03:44 by sgrindhe         ###   ########.fr       */
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

void				move_to_0_0(tetrimino **tets, int num_of_squares);
tetrimino			**make_tetriminos(int quantity);
unsigned int		check_file_for_squares(int fd);
int					count_connections(tetrimino **arr, int num_sqrs);
tetrimino			**convert_squares_to_struct_array(int fd, int num_of_squares);
char				**copy_2d_array(char **to_copy, int width, int height);
void				print_2d_array(char **array);
void				free_2d_array(char **to_free);
void				output_then_exit(char *str);
void				fill_2d_array(char **array, char c);

#endif
