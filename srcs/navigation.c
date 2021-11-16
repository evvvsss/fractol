/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:05:07 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 20:03:30 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	actions(t_win *win)
{
	int	c1;
	int	c2;
	int	c3;

	c1 = 0x6633cc;
	c2 = 0x3399cc;
	c3 = 0xcc3366;
	mlx_string_put(win->mlx, win->win, WIDTH * 0.86, 50, c1, "ZOOM");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.92, 40, c2, "Scroll UP");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.92, 60, c2, "Scroll DOWN");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.86, 105, c1, "MOVE");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.92, 95, c3, "     UP ");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.92, 115, c3, "LEFT | RIGHT");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.92, 135, c3, "    DOWN");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.86, 163, c1, "CHANGE");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.86, 173, c1, "COLOR");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.92, 168, c2, " BUTTON (C)");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.86, 220, c1, "EXIT");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.92, 220, c3, "BUTTON (ESC) ");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.86, 280, c1, "ITERATION");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.95, 270, c2, "PLUS +");
	mlx_string_put(win->mlx, win->win, WIDTH * 0.95, 290, c2, "MINUS -");
}
