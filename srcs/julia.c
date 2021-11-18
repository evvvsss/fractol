/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:27 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:05:58 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	julia(int i, t_fractal *fr)
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
	color = 0xfbf9f0;
	while (ft_power(Z_re, 2.0) + ft_power(Z_im, 2.0) <= 4 && i < fr->max_iter)
	{
		color += 0xfff8f5;
		Z_im = 2 * Z_re * Z_im + fr->julia_im;
		Z_re = re2 - im2 + fr->julia_re;
		re2 = ft_power(Z_re, 2.0);
		im2 = ft_power(Z_im, 2.0);
		i++;
	}
	if (i == fr->max_iter)
		color = 0xff7f7f;
	return (color);
}
