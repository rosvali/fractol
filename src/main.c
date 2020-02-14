/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:29:50 by raguillo          #+#    #+#             */
/*   Updated: 2019/09/12 15:29:52 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_var	var;

	if (argc == 2)
	{
		if (ft_strcmp("mandelbrot", argv[1]) == 0 ||
			ft_strcmp("burningship", argv[1]) == 0 ||
			ft_strcmp("julia", argv[1]) == 0)
		{
			var.name = argv[1];
			init_off(&var);
			fractol(&var);
			mlx_destroy_image(var.mlx.ptr, var.mlx.img_ptr);
			mlx_destroy_window(var.mlx.ptr, var.mlx.window);
		}
		else
			ft_putendl("usage: 'mandelbrot' 'burningship' or 'julia'");
	}
	else
		ft_putendl("usage: 'mandelbrot' 'burningship' or 'julia'");
	sleep(1000);
	return (0);
}
