/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:16:15 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:16:16 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	h;

	h = c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == h)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == h)
		return ((char *)s + i);
	return (NULL);
}
