/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:32:11 by bferny            #+#    #+#             */
/*   Updated: 2021/10/23 23:11:00 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx_opengl_20191021/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# define KEY_ESC				53
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				126
# define KEY_MINUS				78
# define KEY_UP					125
# define KEY_PLUS				69
# define KEY_C					8
# define SCROLL_UP				4
# define SCROLL_DOWN			5
# define KEY_PRESS				2
# define KEY_RELEASE			3
# define WHEEL					4
# define BUTTON_RELEASE			5
# define MOTION_NOTIFY			6
# define EXPOSE					12
# define DESTROY				17

# define MASK_KEY_PRESS			1L
# define MASK_KEY_RELEASE		2L
# define MASK_WHEEL				4L
# define MASK_BUTTON_RELEASE	8L
# define MASK_POINTER_MOTION	64L
# define MASK_EXPOSE			32768L
# define MASK_DESTROY			131072L

# define ZOOM_PLUS				1.2
# define ZOOM_MINUS				0.8
# define SHIFT					0.11

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
	int			x;
	int			y;
	int			color;
}				t_data;

typedef struct s_fractal
{
	double			re_min;
	double			re_max;
	double			im_min;
	double			im_max;
	double			calibration_re;
	double			calibration_im;
	double			mndlbr_re;
	double			mndlbr_im;
	double			julia_re;
	double			julia_im;
	int				name;
	int				color;
	int				max_iter;
	t_data			*vars;
}				t_fractal;

#endif