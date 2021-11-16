/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:36 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:05:14 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	mandelbrot(int i, t_fractal *fr)
{
	double		Z_re;
	double		Z_im;
	double		re2;
	double		im2;
	int			color;

	Z_re = fr->C_re;
	Z_im = fr->C_im;
	re2 = ft_power(Z_re, 2.0);
	im2 = ft_power(Z_im, 2.0);
	color = 0xba9fef;
	while (ft_power(Z_re, 2.0) + ft_power(Z_im, 2.0) <= 4 && i < fr->max_iter)
	{
		color += 0xf0f0ff;
		Z_im = 2 * Z_re * Z_im + fr->C_im;
		Z_re = re2 - im2 + fr->C_re;
		re2 = ft_power(Z_re, 2.0);
		im2 = ft_power(Z_im, 2.0);
		i++;
	}
	if (i == fr->max_iter)
		color = 0x7986e3;
	return (color);
}
