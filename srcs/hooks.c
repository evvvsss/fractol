/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:49:02 by bferny            #+#    #+#             */
/*   Updated: 2021/11/11 22:30:32 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	closer( t_data *data, t_fractal *fr)
{
	printf("%s", "в функции closer\n");
	exit(0);
	free(data);
	free(fr);
}

double	fractal_value(int *i, t_fractal *fr)
{
	printf("%s", "в функции fractal value\n");
	if (fr->name == 1)
		return (mandelbrot(i, fr));
	else if (fr->name == 2)
		return (julia(i, fr));
	// else if (fr->name == 2)
	// 	return (mandelbar(i, fr));
	else
		return (0.0);
}

int	my_keys(int key, t_data *data, t_fractal **fr)
{
	// t_fractals	*fr;

	// fractal = window->fractal;
	if (key == KEY_ESC)
		closer(data, *fr);
	else if (key == KEY_MINUS)
		(*fr)->max_iter = (int)((*fr)->max_iter * 0.5);
	else if (key == KEY_PLUS)
		(*fr)->max_iter = (int)((*fr)->max_iter * 2);
	// else if (key == KEY_LEFT || key == KEY_DOWN
	// 	|| key == KEY_RIGHT || key == KEY_UP)
	// 	my_move(key, data);
	else if (key == KEY_COLOR)
	{
		(*fr)->color += 1;
		(*fr)->color %= 4;
	}
	else
		return (key);
	second_step(data, *fr);
	return (key);
}

int	my_zoom(int wheel, int x, int y, t_data *data, t_fractal *fr)
{
	double	zoom;
	double	re;
	double	im;

	zoom = 1.0;
	if (wheel == SCROLL_UP || wheel == SCROLL_DOWN)
	{
		if (wheel == SCROLL_UP)
			zoom *= ZOOM_PLUS;
		else
			zoom *= ZOOM_MINUS;
		re = fr->re_min + x * fr->new_re;
		im = fr->im_min + y * fr->new_im;
		fr->re_min = re + (fr->re_min - re) * zoom;
		fr->im_min = im + (fr->im_min - im) * zoom;
		fr->re_max = re + (fr->re_max - re) * zoom;
		fr->im_max = im + (fr->im_max - im) * zoom;
		second_step(data, fr);
	}
	return (0);
}

void	hooks(t_data *data/*, char **argv*/)
{
	mlx_hook(data->win, KEY_PRESS, MASK_KEY_PRESS, my_keys, data);
	mlx_hook(data->win, WHEEL, MASK_WHEEL, my_zoom, data);
	///дописать 
}
