/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:29:24 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 00:30:59 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		make_sized_array(int size, int nb, int fd)
{
	int digit_array[size];
	int hold_size;

	hold_size = size;
	while (size > 0)
	{
		digit_array[size - 1] = nb % 10;
		nb = nb / 10;
		size--;
	}
	while (size < hold_size)
	{
		ft_putchar_fd(digit_array[size] + 48, fd);
		size++;
	}
}

void			ft_putnbr_fd(int nb, int fd)
{
	int digit_counter;
	int num_holder;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb == -2147483648)
	{
		ft_putnbr_fd(2, fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	num_holder = nb;
	digit_counter = 1;
	while (num_holder >= 10)
	{
		num_holder = num_holder / 10;
		digit_counter++;
	}
	make_sized_array(digit_counter, nb, fd);
}
