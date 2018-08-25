/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:04:57 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/08 22:38:59 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (1);
		return (0);
	}
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
