/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:32:00 by bferny            #+#    #+#             */
/*   Updated: 2021/11/12 20:34:23 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"


// что-то не прекращает работу цикла мандельброта

void	my_mlx_pixel_put(t_data *vars, int x, int y, int color)
{
	char	*dst;

	//vars->color = color;
	printf("%d%s", color, " cvet my_mlx_pixel_put\n");
	dst = vars->addr + (y * vars->line_length
			+ x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	printf("%s", "в функции my_mlx_pixel_put\n");
}

int	choose_name(t_fractal *fr, int argc, char **argv)
{
	printf("%s", "в функции choose name\n");
	if (ft_strncmp(argv[1], "mandelbrot\0", 11) == 0)
		return (1);
	if (ft_strncmp(argv[1], "julia\0", 6) == 0)
	{	
		if (argc == 2)
		{
			fr->julia_re = 0.5;
			fr->julia_im = -0.5;
		}
		else if (argc == 4)
		{
			fr->julia_re = ft_atof(argv[2]);
			fr->julia_im = ft_atof(argv[3]);
		}
		else
			ft_error(-1);
		return (2);
	}
	else
	{
		write(2, "wrong fractal name\n", 19);
		exit (0);
		return (0);
	}
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
	t_data		*vars;
	t_fractal	*fr;

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
	printf("%s", "в функции draw_window\n");
	fr = first_step(argc, argv);
	hooks(vars);
	second_step(vars, fr);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (vars);
}

int	main(int argc, char **argv)
{
	t_data	*vars;

	// if (argc < 2)
	// 	return (1);
	vars = draw_window(argc, argv);
	printf("%s", "в функции main\n");
	mlx_loop(vars->mlx);
	return (0);
}
