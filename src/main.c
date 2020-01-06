/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:29:50 by raguillo          #+#    #+#             */
/*   Updated: 2019/09/12 15:29:52 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_var	*var;

	if (argc == 2)
	{
		if (!(var = malloc(sizeof(t_var))))
			return (0);
		var->name = argv[1];
		var->zoom = 0.3;
		init_off(var);
		if (ft_strcmp("mandelbrot", var->name) == 0 || ft_strcmp("burningship", var->name) == 0 || ft_strcmp("julia", var->name) == 0)
			fractol(var);
		else
			write(1, "fractol: usage: 'mandelbrot' 'burningship' or 'julia'\n", 55);
	}
	else
		write(1, "fractol: usage: 'mandelbrot' 'burningship' or 'julia'\n", 55);
	return (0);
}
