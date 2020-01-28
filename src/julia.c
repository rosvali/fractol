/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:06:42 by raguillo          #+#    #+#             */
/*   Updated: 2020/01/08 11:06:43 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		julia(t_var *var)
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
			var->zx = (x - var->w / 2) / var->zoom + var->x_off;
			var->zy = (y - var->h / 2) / var->zoom + var->y_off;
			julia_algo(var);
			if (var->i == var->maxi)
				black(var, x, y);
			else
				color(var, x, y);
			y++;
		}
		x++;
	}
}

void		julia_algo(t_var *var)
{
	var->i = 0;
	while (var->zx * var->zx + var->zy * var->zy < 4 && var->i < var->maxi)
	{
		var->tmp = var->zx * var->zx - var->zy * var->zy + var->cx;
		var->zy = var->zx * var->zy + var->zx * var->zy + var->cy;
		var->zx = var->tmp;
		var->i = var->i + 1;
	}
}
