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

int		keyhook(int keycode, t_var *var)
{
	//printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	initvar(t_var *var)
{
	var->x = 0;
	var->y = 0;
	var->zx = 0;
	var->zy = 0;
	var->cx = 0;
	var->cy = 0;
	var->zoom = 100;
	var->tmp = 0;
	var->i = 0;
	var->maxi = 50;
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

static void	black(t_var *var)
{
	var->mlx.img_data[((int)(var->y * WIDTH + (int)var->x) * 4) + 2] = 0;
	var->mlx.img_data[(((int)var->y * WIDTH + (int)var->x) * 4) + 1] = 0;
	var->mlx.img_data[(((int)var->y * WIDTH + (int)var->x) * 4)] = 0;
}

static void	color(t_var *var)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (var->i * 255) / var->maxi;
	g = (var->i * 255) / var->maxi;
	b = (var->i * 255) / var->maxi;
	var->mlx.img_data[((int)(var->y * WIDTH + (int)var->x) * 4) + 2] = r;
	var->mlx.img_data[(((int)var->y * WIDTH + (int)var->x) * 4) + 1] = g;
	var->mlx.img_data[((int)(var->y * WIDTH + (int)var->x) * 4)] = b;
}

void	mandelbrot(t_var *var)
{
	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	int k = 0;
	initvar(var);
	while (var->x < WIDTH)
	{
		var->y = 0;
		while (var->y < HEIGHT)
		{
			var->cx = var->x / var->zoom + x1;
			var->cy = var->y / var->zoom + y1;
			var->i = 0;
			var->zx = 0;
			var->zy = 0;
			while (var->zx * var->zx + var->zy * var->zy < 4 && var->i < var->maxi)
			{
				var->tmp = var->zx;
				var->zx = var->zx * var->zx - var->zy * var->zy + var->cx;
				var->zy = 2 * var->zy * var->tmp + var->cy;
				var->i = var->i + 1;
			}
			printf("%d(%d)\n", var->i, k);
			k++;
			if (var->i == var->maxi)
				black(var);
			else
				color(var);
			var->y++;
		}
		var->x++;
	}
}