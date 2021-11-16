/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:49:02 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:08:51 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	my_close(int key, t_data *data, t_fractal *fr)
{
	free(data);
	free(fr);
	exit(0);
	return (key);
}

int	my_keys(int key, t_win *win)
{
	if (key == KEY_ESC)
		my_close(key, win->data, win->fr);
	else if (key == KEY_MINUS)
		win->fr->max_iter = (int)(win->fr->max_iter * 0.5);
	else if (key == KEY_PLUS)
		win->fr->max_iter = (int)(win->fr->max_iter * 2 + 5);
	else if (key == KEY_LEFT || key == KEY_DOWN
		|| key == KEY_RIGHT || key == KEY_UP)
		my_shifter(key, win);
	else if (key == KEY_COLOR)
		win->fr->color += 1;
	else if (key == KEY_STOP)
		win->fr->stop = !win->fr->stop;
	mlx_clear_window(win->mlx, win->win);
	draw_pixels(win);
	mlx_put_image_to_window(win->mlx, win->win, win->data->img, 0, 0);
	actions(win);
	return (key);
}

int	my_zoom(int wheel, int x, int y, t_win *win)
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
		re = win->fr->re_min + x * win->fr->step_re;
		im = win->fr->im_min + y * win->fr->step_im;
		win->fr->re_min = re + (win->fr->re_min - re) * zoom;
		win->fr->im_min = im + (win->fr->im_min - im) * zoom;
		win->fr->re_max = re + (win->fr->re_max - re) * zoom;
		win->fr->im_max = im + (win->fr->im_max - im) * zoom;
		mlx_clear_window(win->mlx, win->win);
		draw_pixels(win);
		mlx_put_image_to_window(win->mlx, win->win, win->data->img, 0, 0);
		actions(win);
	}
	return (0);
}

int	my_motion(int x, int y, t_win *win)
{
	if (win->fr->stop % 2 == 1)
	{
		win->fr->julia_re = 4 * ((double)x / WIDTH - 0.5);
		win->fr->julia_im = 4 * (double)(HEIGHT - y) / HEIGHT - 0.5;
	}
	mlx_clear_window(win->mlx, win->win);
	draw_pixels(win);
	mlx_put_image_to_window(win->mlx, win->win, win->data->img, 0, 0);
	actions(win);
	return (0);
}

void	my_shifter(int key, t_win *win)
{
	double	shift;

	shift = (win->fr->re_max - win->fr->re_min) * SHIFT;
	if (key == KEY_LEFT)
	{
		win->fr->re_min -= shift;
		win->fr->re_max -= shift;
	}
	else if (key == KEY_RIGHT)
	{
		win->fr->re_min += shift;
		win->fr->re_max += shift;
	}
	else if (key == KEY_UP)
	{
		win->fr->im_min += shift;
		win->fr->im_max += shift;
	}
	else
	{
		win->fr->im_min -= shift;
		win->fr->im_max -= shift;
	}
}
