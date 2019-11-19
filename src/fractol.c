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

int		keyhook(int keycode, t_var *var)
{
	//printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	initvar(t_var *var)
{
	var->px.pr = 0;
	var->px.pi = 0;
	var->px.ci = 0;
	var->px.cr = 0;
	var->px.zoom = 1;
	var->px.tmp = 0;
}

void	fractol(t_var *var)
{
	var->mlx.ptr = mlx_init();
	var->mlx.window = mlx_new_window(var->mlx.ptr, WIDTH, HEIGHT, var->name);
	var->mlx.img_ptr = mlx_new_image(var->mlx.ptr, WIDTH, HEIGHT);
	var->mlx.img_data = (int *)mlx_get_data_addr(var->mlx.img_ptr,
		&var->mlx.img_bpp, &var->mlx.img_size_l, &var->mlx.img_endian);
	mandelbrot(var);
	mlx_key_hook(var->mlx.window, keyhook, var);
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
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			var->px.cr = (x - WIDTH) / (var->px.zoom * WIDTH);
			var->px.ci = (y - HEIGHT) / (var->px.zoom * HEIGHT);
			while (i < HEIGHT)
			{
				var->px.tmp = var->px.pr * var->px.pr - var->px.pi * var->px.pi + var->px.cr;
				var->px.pi = var->px.pr * var->px.pi + var->px.pr * var->px.pi + var->px.ci;
				var->px.pr = var->px.tmp;
				i++;
			}
			var->mlx.img_data[y * WIDTH + x] = 0xFFFFFF;
			x++;
		}
		y++;
		x = 0;
		i = 0;
	}
}
