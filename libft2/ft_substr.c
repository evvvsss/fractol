/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:16:19 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:16:21 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	b = malloc((len + 1) * sizeof(char));
	if (!b)
		return (NULL);
	while (s[start + i] != '\0' && len > 0)
	{
		b[i] = s[start + i];
		i++;
		len--;
	}
	b[i] = '\0';
	return (b);
}
