/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:06:34 by raguillo          #+#    #+#             */
/*   Updated: 2020/01/08 11:06:36 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_var *var)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	init_var(var);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			var->cx = (x - var->w / 2) / var->zoom + var->x_off;
			var->cy = (y - var->h / 2) / var->zoom + var->y_off;
			mandelbrot_algo(var);
			if (var->i == var->maxi)
				black(var, x, y);
			else
				color(var, x, y);
			y++;
		}
		x++;
	}
}

void		mandelbrot_algo(t_var *var)
{
	var->i = 0;
	var->zx = var->cx;
	var->zy = var->cy;
	while (var->zx * var->zx + var->zy * var->zy < 4 && var->i < var->maxi)
	{
		var->tmp = var->zx;
		var->zx = var->zx * var->zx - var->zy * var->zy + var->cx;
		var->zy = 2 * var->zy * var->tmp + var->cy;
		var->i = var->i + 1;
	}
}
