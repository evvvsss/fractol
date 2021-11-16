/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:28:12 by bferny            #+#    #+#             */
/*   Updated: 2021/11/14 20:29:47 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	main(int argc, char **argv)
{
	t_win	*win;

	if (argc < 2)
	{
		write(2, "I need moooore args\n", 20);
		return (1);
	}
	win = draw_window(argc, argv);
	printf("%s", "в функции main\n");
	return (0);
}
