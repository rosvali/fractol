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
	return (0);
}

int		mouse_hook(int button, int x, int y, t_var *var)
{
	//printf("%d\n", button);
	if (button == 4)
	{
		// var->x_off = x - WIDTH / 2;
		// var->y_off = y - HEIGHT / 2;
		var->zoom += 0.1;
	}
	if (button == 5)
	{
		var->zoom -= 0.1;
	}
	printf("x =%d\n", x);
	printf("y =%d\n", y);
	return (0);
}
