/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:32:00 by bferny            #+#    #+#             */
/*   Updated: 2021/10/23 23:28:05 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	my_mlx_pixel_put(t_data *vars, int x, int y, int color)
{
	char	*dst;

	vars->x = x;
	vars->y = y;
	vars->color = color;
	dst = vars->addr + (vars->y * vars->line_length
			+ vars->x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = vars->color;
}

t_fractal	*draw_fractal(int argc, char **argv)
{
	t_fractal	*fr;

	fr = (t_fractal *)malloc(sizeof(t_fractal));
	if (fr == NULL)
		return (NULL);
	
}

t_data	*draw_pixels(t_data *vars)
{
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (vars->addr == NULL)
		return (NULL);
	return (vars);
}

t_data	*draw_window(int argc, char **argv)
{
	t_data	*vars;

	argc = 9;
	argv = NULL;
	vars = (t_data *)malloc(sizeof(t_data));
	if (vars == NULL)
		return (NULL);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (NULL);
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Fractoool!");
	if (vars->win == NULL)
		return (NULL);
	vars = draw_pixels(vars);
	if (vars == NULL)
		return (NULL);
	my_mlx_pixel_put(vars, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (vars);
}

int	main(int argc, char **argv)
{
	t_data	*vars;

	// if (argc < 2)
	// 	return (1);
	vars = draw_window(argc, argv);
	mlx_loop(vars->mlx);
	return (0);
}
