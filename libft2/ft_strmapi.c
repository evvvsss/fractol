/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:16:07 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:16:08 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*b;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	b = ft_strdup(s);
	if ((b == NULL) || !s || !f)
		return (NULL);
	while (b[i] != '\0')
	{
		b[i] = f(i, b[i]);
		i++;
	}
	b[i] = '\0';
	return (b);
}
