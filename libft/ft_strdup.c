/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:38:12 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 23:17:37 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		counter;
	char	*strcp;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	strcp = (char*)malloc((sizeof(char) * (i + 1)));
	counter = 0;
	while (strcp && counter <= i)
	{
		strcp[counter] = src[counter];
		counter++;
	}
	return (strcp);
}
