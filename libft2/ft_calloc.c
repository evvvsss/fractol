/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:14:41 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:14:42 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*d;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	d = malloc(nmemb * size);
	if (!d)
		return (NULL);
	ft_bzero(d, nmemb * size);
	return (d);
}
