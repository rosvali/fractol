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
		fractol(var);
	}
	else
		write(1, "fractol: usage: 'mandelbrot'\n", 29);
	return (0);
}
