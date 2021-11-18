/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:15:50 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:15:52 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(char const *s, char c)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c && s[i + 1] != '\0')
			k++;
		i++;
	}
	return (k + 1);
}

static size_t	ft_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i] != NULL)
		free(s[i++]);
	free(s);
	return (NULL);
}

static size_t	ft_symbols(const char *s, char c, size_t i)
{
	while (s[i] != '\0' && s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			**b;
	size_t			i;
	size_t			j;
	size_t			num_str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	num_str = ft_count_str(s, c);
	b = (char **)malloc((num_str + 1) * sizeof(char *));
	if (!b)
		return (NULL);
	i = ft_symbols(s, c, i);
	while (j < num_str && s[i] != '\0')
	{
		b[j] = ft_substr(s, i, ft_len(&s[i], c));
		if (!(b[j]))
			return (ft_free(b));
		i = i + ft_len(&s[i], c);
		j++;
		i = ft_symbols(s, c, i);
	}
	b[j] = NULL;
	return (b);
}
