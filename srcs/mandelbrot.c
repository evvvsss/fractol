/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:36 by bferny            #+#    #+#             */
/*   Updated: 2021/11/12 20:38:09 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	mandelbrot(int *i, t_fractal *fr)
{
	double		Z_re;
	double		Z_im;
	double		re2;
	double		im2;

	*i = 0;
	Z_re = fr->C_re;
	Z_im = fr->C_im;
	re2 = ft_power(Z_re, 2.0);
	im2 = ft_power(Z_im, 2.0);
	printf("%s%f", "в круге или нет  ", ft_power(Z_re, 2.0) + ft_power(Z_im, 2.0));
	while (ft_power(Z_re, 2.0) + ft_power(Z_im, 2.0) <= 4 && *i < fr->max_iter)
	{
		fr->color += 0x00010F0F;
		Z_im = 2 * Z_re * Z_im + fr->C_im;
		Z_re = re2 - im2 + fr->C_re;
		re2 = ft_power(Z_re, 2.0);
		im2 = ft_power(Z_im, 2.0);
		(*i)++;
	}
	printf("  %s%d", "i  ", (*i));
	printf("%s", "\nв функции МАНДЕЛЬБРО \n re2 + im2  ");
	printf("%f\n", re2 + im2);
	return (re2 + im2);
}
