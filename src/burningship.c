/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:06:56 by raguillo          #+#    #+#             */
/*   Updated: 2020/01/08 11:06:57 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		burningship(t_var *var)
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
			var->cx = (x - WIDTH) / (var->zoom * WIDTH) + var->x_off;
			var->cy = (y - HEIGHT) / (var->zoom * HEIGHT) + var->y_off;
			burningship_algo(var);
			if (var->i == var->maxi)
				black(var, x, y);
			else
				color(var, x, y);
			y++;
		}
		x++;
	}
}

void		burningship_algo(t_var *var)
{
	var->i = 0;
	var->zx = var->cx;
	var->zy = var->cy;
	while (var->zx * var->zx + var->zy * var->zy < 4 && var->i < var->maxi)
	{
		var->tmp = var->zy;
		var->zy = ft_abs(var->zx * var->zy + var->zx * var->zy) + var->cy;
		var->zx = var->zx * var->zx - var->tmp * var->tmp + var->cx;
		var->i = var->i + 1;
	}
}
