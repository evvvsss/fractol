/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:37:04 by bferny            #+#    #+#             */
/*   Updated: 2021/11/12 20:34:01 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

t_fractal	*first_step(int argc, char **argv)
{
	t_fractal	*fr;

	fr = (t_fractal *)malloc(sizeof(t_fractal));
	if (fr == NULL)
		return (NULL);
	fr->name = choose_name(fr, argc, argv);
	printf("%d", fr->name);
	fr->re_min = -2.0;
	fr->im_min = -2.0;
	fr->re_max = 2.0;
	fr->im_max = 2.0;
	fr->max_iter = 256;
	fr->color = 0;
	printf("%s", "в функции first_step\n");
	return (fr);
}

void	second_step(t_data *data, t_fractal *fr)
{
	t_fractal	*new_fr;
	double		re;
	double		im;

	re = 0.0;
	im = 0.0;
	new_fr = fr;
	printf("%s", "в функции second step\n");
	new_fr->new_re = (new_fr->re_max
			- new_fr->re_min) / WIDTH;
	new_fr->new_im = (new_fr->im_max
			- new_fr->im_min) / HEIGHT;
	third_step(data, fr, re, im);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	navigation(data);
}

void	third_step(t_data *data, t_fractal *fr, int x, int y)
{
	int			i;
	double		current_fractal_value;
	t_fractal	*new_fr;
	//double		color;

	new_fr = fr;
	y = 0;
	while (y < HEIGHT)
	{
		new_fr->C_im = new_fr->im_min + y * new_fr->new_im;
		x = 0;
		while (x < WIDTH)
		{
			new_fr->C_re = new_fr->re_min + x * new_fr->new_re;
			current_fractal_value = fractal_value(&i, new_fr);
			//color = ft_paint(current_fractal_value, i, new_fr);
			my_mlx_pixel_put(data->img, x, y, fr->color);
			x++;
			printf("%s", "в функции third step  ");
			printf("%f %f \n", new_fr->C_re, new_fr->C_im);
		}
		y++;
	}
}
