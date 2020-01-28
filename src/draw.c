/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:59:30 by raguillo          #+#    #+#             */
/*   Updated: 2020/01/08 10:59:37 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double		ft_abs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

void		black(t_var *var, int x, int y)
{
	var->mlx.img_data[((y * WIDTH + x) * 4) + 2] = 0;
	var->mlx.img_data[((y * WIDTH + x) * 4) + 1] = 0;
	var->mlx.img_data[((y * WIDTH + x) * 4)] = 0;
}

void		color(t_var *var, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = ((var->i * var->r) / (var->maxi));
	g = ((var->i * var->g) / (var->maxi));
	b = ((var->i * var->b) / (var->maxi));
	var->mlx.img_data[((y * WIDTH + x) * 4)] = b;
	var->mlx.img_data[((y * WIDTH + x) * 4) + 1] = g;
	var->mlx.img_data[((y * WIDTH + x) * 4) + 2] = r;
}

void		draw(t_var *var)
{
	if (ft_strcmp(var->name, "mandelbrot") == 0)
		mandelbrot(var);
	else if (ft_strcmp(var->name, "burningship") == 0)
		burningship(var);
	else if (ft_strcmp(var->name, "julia") == 0)
		julia(var);
}
