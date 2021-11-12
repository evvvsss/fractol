/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:43:25 by bferny            #+#    #+#             */
/*   Updated: 2021/11/12 20:22:58 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res +(res > 0))
		return (res2);
	else
		return (-res2);
}

double	ft_power(double nbr, double power)
{
	double	n;

	n = 1;
	while (power--)
		n = n * nbr;
	return (n);
}

int	ft_paint(int value, int i, t_fractal *fr)
{
	double	t;
	int		color;

	color = fr->color;
	t = (double)i / (double)(fr->max_iter);
	printf("%d%s", color, "color\n");
	if (color == 0) // fr->name 
		return ((int)(COLOR - (i == fr->max_iter) * COLOR));
	else if (color == 1)
		return ((int)(i * COLOR) & 0x00aefdaf);
	else if (color == 2)
		return (((int)(9 * t * t * 255)) << 16
			| ((int)(7 * (1 - t) * t * 255)) << 8
			| ((int)(3 * (1 - t) * (1 - t) * 255)));
	else if (color == 3)
		return ((int)(9 * (1 - t) * ft_power(t, 3) * 255) << 16
			| (int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8
			| (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255));
	printf("%s", "в функции paint\n");
	return (value);
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
		exit(error);
	}
}

void	navigation(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 800, 40, 0xFFFFFF,
		"-------------ZOOM------------");
	mlx_string_put(data->mlx, data->win, 800, 70, 0xf7f070,
		"       Scroll UP | Scroll DOWN         ");
	mlx_string_put(data->mlx, data->win, 800, 110, 0xFFFFFF,
		"-------------MOVE------------");
	mlx_string_put(data->mlx, data->win, 800, 140, 0xf7f070,
		"        Arrow UP | Arrow DOWN    ");
	mlx_string_put(data->mlx, data->win, 800, 180, 0xf7f070,
		"     Arrow RIGHT | Arrow LIFT ");
	mlx_string_put(data->mlx, data->win, 800, 220, 0xFFFFFF,
		"--------CHANGE COLOR--------");
	mlx_string_put(data->mlx, data->win, 800, 250, 0xf7f070,
		"           BUTTON (C) ");
	mlx_string_put(data->mlx, data->win, 800, 280, 0xFFFFFF,
		"-------------EXIT-----------");
	mlx_string_put(data->mlx, data->win, 800, 310, 0xf7f070,
		"           BUTTON (ESC) ");
	mlx_string_put(data->mlx, data->win, 800, 340, 0xFFFFFF,
		"-----------ITERATION--------");
	mlx_string_put(data->mlx, data->win, 800, 370, 0xf7f070,
		"           PLUS | MINUS     ");
}
