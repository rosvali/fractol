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
	//printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 6)
		var->zoom += 0.1;
	else if (keycode == 7)
		var->zoom -= 0.1;
	else if (keycode == 2 || keycode == 124)
		var->x_off += 0.1;
	else if (keycode == 0 || keycode == 123)
		var->x_off -= 0.1;
	else if (keycode == 13 || keycode == 126)
		var->y_off -= 0.1;
	else if (keycode == 1 || keycode == 125)
		var->y_off += 0.1;
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
	printf("%d\n", button);
	// if (x < WIDTH && y < HEIGHT)
	// {
	// 	var->mzx = x - (var->cx / 2);
	// 	var->mzy = y - (var->cy / 2);
	// 	var->zoom += 0.1;
	// 	var->x_off += x / 2;
	// 	var->y_off += y / 2;
	// }
	// }
	if (button == 4)
	{
		var->zoom += 0.1;
		var->cx = (double)x - (WIDTH / 2);
		var->cy = (double)y - (HEIGHT / 2);
		var->w -= var->cx;
		var->h -= var->cy;
		// var->x_off -= (double)x / var->zoom * var->zoom; //(double)x - (var->x_off / 2);
		// var->y_off -= (double)y / var->zoom * var->zoom;//(double)y - (var->y_off / 2);
	}
	if (button == 5)
	{
		var->zoom -= 0.1;
		var->cx = (double)x - (WIDTH / 2);
		var->cy = (double)y - (HEIGHT / 2);
		// var->x_off += 1.08;
		// var->y_off += 1.08;
	}
	mlx_clear_window(var->mlx.ptr, var->mlx.window);
	draw(var);
	// mlx_put_image_to_window(var->mlx.ptr, var->mlx.window,
	// 	var->mlx.img_ptr, 0, 0);
	return (0);
}

int		motion_hook(int x, int y, t_var *var)
{

	if (x < WIDTH && y < HEIGHT)
	{
		if (ft_strcmp(var->name, "julia") == 0)
		{
			var->cx = (((double)x - (WIDTH / 2)) / 1000) * 2;
			var->cy = (((double)y - (HEIGHT / 2)) / 1000) * 2;
			draw(var);
			mlx_put_image_to_window(var->mlx.ptr, var->mlx.window,
			var->mlx.img_ptr, 0, 0);
		}
	}
	printf("%f\n", var->cx);
	printf("%f\n", var->cy);
	// mlx_put_image_to_window(var->mlx.ptr, var->mlx.window,
	// 	var->mlx.img_ptr, 0, 0);
	return (0);
}

// if (keycode == 4 || keycode == 1)
// 	{
// 		if (x < WIDTH && y < HEIGHT && y > 0)
// 		{
// 			param->xz = x - (param->x1 / 2);
// 			param->yz = y - (param->y1 / 2);
// 			param->x1 -= param->xz;
// 			param->y1 -= param->yz;
// 			param->zoom *= 1.5;
// 		}
// 	}
// 	if (keycode == 5 || keycode == 2)
// 	{
// 		if (x < WIDTH && y < HEIGHT && y > 0)
// 		{
// 			param->xz = x - (param->x1 / 2);
// 			param->yz = y - (param->y1 / 2);
// 			param->x1 += param->xz;
// 			param->y1 += param->yz;
// 			param->zoom /= 2;
// 		}
