/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:59:50 by raguillo          #+#    #+#             */
/*   Updated: 2020/01/08 10:59:57 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		loop_hook(t_var *var)
{
	draw(var);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.window,
		var->mlx.img_ptr, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_var *var)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 6)
		var->zoom += 0.1;
	else if (keycode == 7)
		var->zoom -= 0.1;
	else if (keycode == 124)
		var->x_off += 0.01;
	else if (keycode == 123)
		var->x_off -= 0.01;
	else if (keycode == 126)
		var->y_off -= 0.01;
	else if (keycode == 125)
		var->y_off += 0.01;
	else if (keycode == 1)
		var->motion = (var->motion == 0) ? 1 : 0;
	else if (keycode == 15 || keycode == 5 || keycode == 11)
		color_hook(keycode, var);
	return (0);
}

int		color_hook(int keycode, t_var *var)
{
	if (keycode == 15)
	{
		var->r += 20;
		var->r = var->r > 255 ? 0 : var->r;
	}
	else if (keycode == 5)
	{
		var->g += 20;
		var->g = var->g > 255 ? 0 : var->g;
	}
	else if (keycode == 11)
	{
		var->b += 20;
		var->b = var->b > 255 ? 0 : var->b;
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_var *var)
{
	if (button == 4)
	{
		var->zoom += 0.2;
		// var->x_off -= 0.47 - var->zoom;
		// var->y_off -= 0.42 - var->zoom;
		// var->x_off -= ((double)x / WIDTH);
		// var->y_off -= ((double)y / HEIGHT);
		// var->x_off -= 100 / (double)x;
		// var->y_off -= 100 / (double)y;
	}
	if (button == 5)
	{
		var->zoom -= 0.2;
		// var->x_off += (double)x / WIDTH;
		// var->y_off += (double)y / HEIGHT;
		// var->x_off += 100 / (double)x;
		// var->y_off += 100 / (double)y;
	}
	printf("%f\n", var->zoom);
	printf("%f\n", var->x_off);
	printf("%f\n", var->y_off);
	printf("%d\n", x);
	printf("%d\n", y);
	return (0);
}

int		motion_hook(int x, int y, t_var *var)
{
	if (x < WIDTH && y < HEIGHT)
	{
		if (var->motion == 0 && ft_strcmp(var->name, "julia") == 0)
		{
			var->cx = (((double)x - (WIDTH / 2)) / 1000) * 2;
			var->cy = (((double)y - (HEIGHT / 2)) / 1000) * 2;
			draw(var);
			mlx_put_image_to_window(var->mlx.ptr, var->mlx.window,
			var->mlx.img_ptr, 0, 0);
		}
	}
	return (0);
}
