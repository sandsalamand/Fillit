/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 23:39:12 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 00:26:37 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		trim_array(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	long long	num;
	int			i;
	int			bool_negative;

	num = 0;
	bool_negative = 0;
	i = trim_array(str) - 1;
	if (str[i + 1] == '-')
	{
		i++;
		bool_negative = 1;
	}
	else if (str[i + 1] == '+')
		i++;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (bool_negative == 1 ? -num : num);
		num += str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			num *= 10;
	}
	return (bool_negative == 1 ? (int)-num : (int)num);
}
