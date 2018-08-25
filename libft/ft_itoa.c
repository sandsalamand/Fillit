/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:37:09 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/06 00:09:38 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	if (nb == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	if (nb < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-nb));
	}
	else if (nb >= 10)
		str = ft_strjoin(ft_itoa(nb / 10), ft_itoa(nb % 10));
	else if (nb < 10)
	{
		str[0] = nb + '0';
		str[1] = '\0';
	}
	return (str);
}
