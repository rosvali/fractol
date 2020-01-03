/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:19:07 by raguillo          #+#    #+#             */
/*   Updated: 2019/11/21 14:45:02 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		loop_hook(t_var *var)
{
	mandelbrot(var);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.window, var->mlx.img_ptr, 0, 0);
	return (0);
}

int		keyhook(int keycode, t_var *var)
{
	//printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 6)
		var->zoom += 0.1;
	if (keycode == 7)
		var->zoom -= 0.1;
	if (keycode == 1)
		var->x_off += 1;
	return (0);
}

void	initvar(t_var *var)
{
	var->zx = 0;
	var->zy = 0;
	var->cx = 0;
	var->cy = 0;
	var->tmp = 0;
	var->i = 0;
	var->maxi = 50;
}

static void	init_off(t_var *var)
{
	var->x_off = 1;
	var->y_off = 2;
}

void	fractol(t_var *var)
{
	var->mlx.ptr = mlx_init();
	var->mlx.window = mlx_new_window(var->mlx.ptr, WIDTH, HEIGHT, var->name);
	var->mlx.img_ptr = mlx_new_image(var->mlx.ptr, WIDTH, HEIGHT);
	var->mlx.img_data = (int *)mlx_get_data_addr(var->mlx.img_ptr,
		&var->mlx.img_bpp, &var->mlx.img_size_l, &var->mlx.img_endian);
	mlx_key_hook(var->mlx.window, keyhook, var);
	mandelbrot(var);
	init_off(var);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.window, var->mlx.img_ptr, 0, 0);
	mlx_loop_hook(var->mlx.ptr, loop_hook, var);
	mlx_loop(var->mlx.ptr);
}

void	black(t_var *var, int x, int y)
{
	var->mlx.img_data[((int)(y * WIDTH + (int)x)) + 2] = 0;
	var->mlx.img_data[(((int)y * WIDTH + (int)x)) + 1] = 0;
	var->mlx.img_data[(((int)y * WIDTH + (int)x))] = 0;
}

void	color(t_var *var, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (var->i * 255) / var->maxi;
	g = (var->i * 255) / var->maxi;
	b = (var->i * 255) / var->maxi;
	var->mlx.img_data[((int)(y * WIDTH + (int)x)) + 2] = r;
	var->mlx.img_data[(((int)y * WIDTH + (int)x)) + 1] = g;
	var->mlx.img_data[((int)(y * WIDTH + (int)x))] = b;
}

void	mandelbrot(t_var *var)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	initvar(var);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			var->cx = (x - WIDTH) / (var->zoom * WIDTH);
			var->cy = (y - HEIGHT) / (var->zoom * HEIGHT);
			//var->cx = x / WIDTH * var->zoom;
			//var->cy = y / HEIGHT * var->zoom;
			var->i = 0;
			var->zx = 0;
			var->zy = 0;
			while (var->zx * var->zx + var->zy * var->zy < 4 && var->i < var->maxi)
			{
				// var->tmp = var->zx;
				// var->zx = var->zx * var->zx - var->zy * var->zy + var->cx;
				// var->zy = 2 * var->zy * var->tmp + var->cy;
				// var->i = var->i + 1;

				var->tmp = var->zx * var->zx - var->zy * var->zy + var->cx;
				var->zy = var->zx * var->zy + var->zx * var->zy + var->cy;
				var->zx = var->tmp;
				var->i = var->i + 1;
			}
			if (var->i == var->maxi)
				black(var, x, y);
			else
				color(var, x, y);
			y++;
		}
		x++;
	}
}
