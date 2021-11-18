/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:16:02 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:16:04 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)src;
	if (!dst || !src)
		return (0);
	while (size > 1)
	{
		*(dst + i) = s[i];
		if (s[i] == '\0')
			return (ft_strlen(src));
		i++;
		size --;
	}
	if (size > 0)
		*(dst + i) = '\0';
	return (ft_strlen(src));
}
