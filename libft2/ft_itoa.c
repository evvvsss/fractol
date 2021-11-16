/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:15:02 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:15:04 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(int n)
{
	size_t	k;

	k = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (0);
	if (n < 0)
	{
		k++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		k++;
	}
	return (k - 1);
}

static char	zero(int n, char d)
{
	if (n == 0 && d != '0')
		d = '-';
	else
		d = (n % 10) + 48;
	return (d);
}

char	*ft_itoa(int n)
{
	char	*d;
	size_t	i;

	i = len(n);
	if (n < 0 && n != -2147483648)
		n = -n;
	d = malloc((i + 2) * sizeof(char));
	if (!d)
		return (NULL);
	d[i + 1] = '\0';
	if (n == -2147483648)
	{
		d[i--] = '8';
		n = 214748364;
	}
	if (i == 0)
		d[0] = '0';
	while (i > 0 && n != -2147483648)
	{
		d[i--] = (n % 10) + 48;
		n = n / 10;
	}
	d[0] = zero(n, d[0]);
	return (d);
}
