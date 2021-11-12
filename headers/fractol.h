/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:32:11 by bferny            #+#    #+#             */
/*   Updated: 2021/11/12 20:20:13 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libmlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define KEY_PRESS				2
# define KEY_RELEASE			3
# define WHEEL					4
# define SCROLL_UP				4
# define SCROLL_DOWN			5
# define BUTTON_RELEASE			5
# define KEY_COLOR				8
# define KEY_ESC				53
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				126
# define KEY_UP					125
# define KEY_MINUS				78
# define KEY_PLUS				69
# define MOTION_NOTIFY			6

# define MASK_KEY_PRESS			1L
# define MASK_KEY_RELEASE		2L
# define MASK_WHEEL				4L
# define MASK_BUTTON_RELEASE	8L
# define MASK_POINTER_MOTION	64L

# define ZOOM_PLUS				1.5
# define ZOOM_MINUS				0.5
# define SHIFT					0.1

# define HEIGHT					800
# define WIDTH					900
# define COLOR					0xeafbcb //0xcbd2fb

typedef struct s_data
{
	void		*img;
	char		*addr;
	void		*mlx;
	void		*win;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			offset;
	int			color;
}				t_data;

typedef struct s_fractal
{
	double			re_min;
	double			re_max;
	double			im_min;
	double			im_max;
	double			new_re;
	double			new_im;
	double			C_re;
	double			C_im;
	double			julia_re;
	double			julia_im;
	int				name;
	int				color;
	int				max_iter;
}				t_fractal;

// функция инит для структур

void		my_mlx_pixel_put(t_data *vars, int x, int y, int color);
int			choose_name(t_fractal *fr, int argc, char **argv);
t_fractal	*first_step(int argc, char **argv);
t_data		*draw_pixels(t_data *vars);
t_data		*draw_window(int argc, char **argv);
void		closer(t_data *data, t_fractal *fr);
double		fractal_value(int *i, t_fractal *fr);
void		third_step(t_data *data, t_fractal *fr, int x, int y);
void		second_step(t_data *data, t_fractal *fr);
//int			my_keys(int key, t_data *data, t_fractal **fr);
//int	my_zoom(int wheel, int x, int y, t_data *data);
void		hooks(t_data *data);
double		ft_atof(const char *str);
double		ft_power(double nbr, double power);
int			ft_paint(int value, int i, t_fractal *fr);
void		ft_error(int error);
double		julia(int *i, t_fractal *fr);
double		mandelbrot(int *i, t_fractal *fr);
void		navigation(t_data *navigation);

#endif