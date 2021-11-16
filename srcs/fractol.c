/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:32:00 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:09:34 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	my_mlx_pixel_put(t_data *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	hooks(t_win *win)
{
	mlx_hook(win->win, KEY_PRESS, MASK_KEY_PRESS, my_keys, win);
	mlx_hook(win->win, KEY_ESC, MASK_DESTROY, my_close, win);
	mlx_hook(win->win, WHEEL, MASK_WHEEL, my_zoom, win);
	if (win->fr->name == 2)
		mlx_hook(win->win, MOTION_NOTIFY, MASK_POINTER_MOTION, my_motion, win);
}

int	fractal_value(t_fractal *fr)
{
	if (fr->name == 1)
		return (mandelbrot(0, fr));
	else if (fr->name == 2)
		return (julia(0, fr));
	else if (fr->name == 3)
		return (ships(0, fr));
	else
		return (0);
}

int	choose_name(t_win *win, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot\0", 11) == 0)
		return (1);
	if (ft_strncmp(argv[1], "julia\0", 6) == 0)
	{	
		if (argc == 2)
		{
			win->fr->julia_re = -0.8;
			win->fr->julia_im = 0.4;
		}
		else if (argc == 4)
		{
			win->fr->julia_re = ft_atof(argv[2]);
			win->fr->julia_im = ft_atof(argv[3]);
		}
		else
			ft_error(-1);
		return (2);
	}
	if (ft_strncmp(argv[1], "ships\0", 6) == 0)
		return (3);
	else
		ft_error(-1);
	return (0);
}
