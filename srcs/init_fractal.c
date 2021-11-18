/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:37:04 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:11:46 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	init_fractal(t_win *win, int argc, char **argv)
{
	t_fractal	*fr;

	fr = (t_fractal *)malloc(sizeof(t_fractal));
	if (fr == NULL)
		ft_error(1);
	win->fr = fr;
	fr->julia_re = 0;
	fr->julia_im = 0;
	fr->name = choose_name(win, argc, argv);
	fr->re_min = -3.0;
	fr->im_min = -3.0;
	fr->re_max = 3.0;
	fr->im_max = 3.0;
	fr->max_iter = 128;
	fr->step_re = (fr->re_max - fr->re_min) / WIDTH;
	fr->step_im = (fr->im_max - fr->im_min) / HEIGHT;
	fr->C_re = 0;
	fr->C_im = 0;
	fr->color = 0;
	fr->stop = 0;
}
