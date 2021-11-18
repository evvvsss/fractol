/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:32:11 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:08:19 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libmlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
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
# define KEY_STOP				1

# define MASK_KEY_PRESS			1L
# define MASK_KEY_RELEASE		2L
# define MASK_WHEEL				4L
# define MASK_BUTTON_RELEASE	8L
# define MASK_POINTER_MOTION	64L
# define MASK_DESTROY			131072L

# define ZOOM_PLUS				1.5
# define ZOOM_MINUS				0.5
# define SHIFT					0.1

# define HEIGHT					900
# define WIDTH					1100
# define COLOR					0xeafbcb //0xcbd2fb

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			offset;
}				t_data;

typedef struct s_fractal
{
	double			re_min;
	double			re_max;
	double			im_min;
	double			im_max;
	double			step_re;
	double			step_im;
	double			C_re;
	double			C_im;
	double			julia_re;
	double			julia_im;
	int				name;
	int				color;
	int				max_iter;
	int				stop;
}				t_fractal;

typedef struct s_win
{
	void			*win;
	void			*mlx;
	t_fractal		*fr;
	t_data			*data;
}				t_win;

void		my_mlx_pixel_put(t_data *vars, int x, int y, int color);
int			choose_name(t_win *win, int argc, char **argv);
void		init_fractal(t_win *win, int argc, char **argv);
t_data		*draw_image(void *mlx);
t_win		*draw_window(int argc, char **argv);
void		draw_pixels(t_win *win);
int			fractal_value(t_fractal *fr);
int			my_keys(int key, t_win *win);
int			my_close(int key, t_data *data, t_fractal *fr);
int			my_zoom(int wheel, int x, int y, t_win *win);
void		my_shifter(int key, t_win *win);
int			my_motion(int x, int y, t_win *win);
void		hooks(t_win *win);
void		actions(t_win *win);
double		ft_atof(const char *str);
double		ft_power(double nbr, double power);
void		ft_error(int error);
int			julia(int i, t_fractal *fr);
int			mandelbrot(int i, t_fractal *fr);
int			ships(int i, t_fractal *fr);

#endif