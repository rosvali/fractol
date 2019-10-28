/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:19:07 by raguillo          #+#    #+#             */
/*   Updated: 2019/09/18 15:20:06 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initvar(t_var *var)
{
	var->pixel.pr = 0;
	var->pixel.pi = 0;
	var->pixel.newr = 0;
	var->pixel.newi = 0;
	var->pixel.oldr = 0;
	var->pixel.oldi = 0;
	var->pixel.zoom = 1;
	var->pixel.movex = -0.5;
	var->pixel.movey = 0;
	var->pixel.maxi = HEIGHT;
}

void	fractol(t_var *var)
{
	var->mlx.ptr = mlx_init();
	var->mlx.window = mlx_new_window(var->mlx.ptr, WIDTH, HEIGHT, var->name);
	var->mlx.img_ptr = mlx_new_image(var->mlx.ptr, WIDTH, HEIGHT);
	var->mlx.img_data = (int *)mlx_get_data_addr(var->mlx.img_ptr,
		&var->mlx.img_bpp, &var->mlx.img_size_l, &var->mlx.img_endian);
	//mandelbrot(var);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.window, var->mlx.img_ptr, 0, 0);
	mlx_loop(var->mlx.ptr);
}

void	mandelbrot(t_var *var)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	initvar(var);
	printf("ok");
	while (y++ < HEIGHT)
	{
		while (x++ < WIDTH)
		{
			var->pixel.pr = 1.5 * (x - WIDTH / 2) / (0.5 * var->pixel.zoom * WIDTH) + var->pixel.movex;
			var->pixel.pi = (y - HEIGHT / 2) / (0.5 * var->pixel.zoom * HEIGHT) + var->pixel.movey;
			while (i < var->pixel.maxi)
			{
				var->pixel.oldr = var->pixel.newr;
				var->pixel.oldi = var->pixel.newi;
				var->pixel.newr = var->pixel.oldr * var->pixel.oldr - var->pixel.oldi + var->pixel.pr;
				var->pixel.newi = 2 * var->pixel.oldr * var->pixel.oldi + var->pixel.pi;
				if ((var->pixel.newr + var->pixel.newi) > 2)
					break ;
			}
			var->mlx.img_data[y + x] = 0xFFFFFF;
			printf("%d\n", y + x);
		}
	}
}