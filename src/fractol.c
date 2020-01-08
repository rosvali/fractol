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

void	initvar(t_var *var)
{
	var->zx = 0;
	var->zy = 0;
	var->cx = 0;
	var->cy = 0;
	var->tmp = 0;
	var->i = 0;
	var->r = 0;
	var->maxi = 50;
}

void	init_off(t_var *var)
{
	if (ft_strcmp("mandelbrot", var->name) == 0)
	{
		var->x_off = 1.1;
		var->y_off = 1.6;
	}
	else if (ft_strcmp("burningship", var->name) == 0)
	{
		var->x_off = 1.2;
		var->y_off = 1.1;
	}
	else if (ft_strcmp("julia", var->name) == 0)
	{
		var->x_off = 1.6;
		var->y_off = 1.6;
	}
	var->xmouse = 0;
	var->ymouse = 0;
}

void	fractol(t_var *var)
{
	var->mlx.ptr = mlx_init();
	var->mlx.window = mlx_new_window(var->mlx.ptr, WIDTH, HEIGHT, var->name);
	var->mlx.img_ptr = mlx_new_image(var->mlx.ptr, WIDTH, HEIGHT);
	var->mlx.img_data = (int *)mlx_get_data_addr(var->mlx.img_ptr,
		&var->mlx.img_bpp, &var->mlx.img_size_l, &var->mlx.img_endian);
	mlx_key_hook(var->mlx.window, key_hook, var);
	mlx_mouse_hook(var->mlx.window, mouse_hook, var);
	draw(var);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.window, var->mlx.img_ptr, 0, 0);
	mlx_loop_hook(var->mlx.ptr, loop_hook, var);
	mlx_loop(var->mlx.ptr);
}
