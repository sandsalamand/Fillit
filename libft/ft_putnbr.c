/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:19:26 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/07/17 09:25:00 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		make_sized_array(int size, int nb)
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
		ft_putchar(digit_array[size] + 48);
		size++;
	}
}

void			ft_putnbr(int nb)
{
	int digit_counter;
	int num_holder;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb == -2147483648)
	{
		ft_putnbr(2);
		ft_putnbr(147483648);
		return ;
	}
	num_holder = nb;
	digit_counter = 1;
	while (num_holder >= 10)
	{
		num_holder = num_holder / 10;
		digit_counter++;
	}
	make_sized_array(digit_counter, nb);
}
