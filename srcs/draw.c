/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:57:03 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:09:10 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

t_win	*draw_window(int argc, char **argv)
{
	t_win		*win;

	win = (t_win *)malloc(sizeof(t_win));
	if (win == NULL)
		return (NULL);
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (NULL);
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, " Fractoool!");
	if (win->win == NULL)
		return (NULL);
	win->data = draw_image(win->mlx);
	if (win->data == NULL)
		return (NULL);
	init_fractal(win, argc, argv);
	hooks(win);
	draw_pixels(win);
	mlx_put_image_to_window(win->mlx, win->win, win->data->img, 0, 0);
	actions(win);
	mlx_loop(win->mlx);
	return (win);
}

t_data	*draw_image(void *mlx)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->addr == NULL)
		return (NULL);
	return (data);
}

void	draw_pixels(t_win *win)
{
	t_fractal	*new_fr;
	int			color;
	int			x;
	int			y;

	y = 0;
	new_fr = win->fr;
	new_fr->step_re = (new_fr->re_max - new_fr->re_min) / WIDTH;
	new_fr->step_im = (new_fr->im_max - new_fr->im_min) / HEIGHT;
	while (y < HEIGHT)
	{
		new_fr->C_im = new_fr->im_min + y * new_fr->step_im;
		x = 0;
		while (x < WIDTH)
		{
			new_fr->C_re = new_fr->re_min + x * new_fr->step_re;
			color = fractal_value(win->fr);
			if (win->fr->color != 0)
				color += win->fr->color * COLOR;
			my_mlx_pixel_put(win->data, x, y, color);
			x++;
		}
		y++;
	}
}
