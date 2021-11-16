/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:15:52 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:15:54 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	n;
	size_t	i;
	char	h;

	h = c;
	n = ft_strlen(s);
	i = 0;
	while (i <= n)
	{
		if (s[i] == h)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
