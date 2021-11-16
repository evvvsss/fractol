/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:43:25 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 21:15:47 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	ft_atof(const char *str)
{
	double	res;
	double	neg;
	double	divider;
	size_t	i;

	divider = 0.1;
	res = 0;
	neg = 1;
	i = -1;
	while (str[i] < '0' || str[i] > '9')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
	}
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + (str[i] - 48) * divider;
		divider /= 10;
		i++;
	}
	return (res * neg);
}

double	ft_power(double nbr, double power)
{
	double	n;

	n = 1;
	while (power--)
		n = n * nbr;
	return (n);
}

void	ft_error(int error)
{
	if (error > 0)
	{
		perror(NULL);
	}
	if (error == -1)
	{
		printf("Error: ./fractol \"fractal_name\" \"re\" \"im\"\n");
		printf("\"fractal_names\":\n");
		printf("\tmandelbrot\n");
		printf("\tjulia\n");
		printf("\tmandelbar\n");
		printf("\tships\n");
		exit(error);
	}
}
