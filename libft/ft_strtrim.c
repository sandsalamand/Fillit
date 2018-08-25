/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrindhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 19:20:47 by sgrindhe          #+#    #+#             */
/*   Updated: 2018/08/05 22:11:28 by sgrindhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(const char c)
{
	if (c != '\0' && (c == ' ' || c == '\n' || c == '\t'))
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		max;
	int			z;

	if (!s)
		return (0);
	max = ft_strlen(s);
	i = -1;
	while (is_whitespace(s[++i]) && i < max)
		;
	z = max - 1;
	while (is_whitespace(s[z--]) && z > -1)
		;
	if (z == -1 || i >= max)
		return (ft_strnew(1));
	else
	{
		max = ++z - i + 1;
		return (ft_strsub(s, i, max));
	}
}
