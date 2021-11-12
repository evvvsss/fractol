/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:27 by bferny            #+#    #+#             */
/*   Updated: 2021/10/27 20:34:20 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	julia(int *i, t_fractal *fr)
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
	while (ft_power(Z_re, 2.0) + ft_power(Z_im, 2.0) <= 4
		&& *i < fr->max_iter)
	{
		Z_im = 2 * Z_re * Z_im + fr->julia_im;
		Z_re = re2 - im2 + fr->julia_re;
		re2 = ft_power(Z_re, 2.0);
		im2 = ft_power(Z_im, 2.0);
		(*i)++;
	}
	return (re2 + im2);
}
