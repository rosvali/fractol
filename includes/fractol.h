/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:44:43 by raguillo          #+#    #+#             */
/*   Updated: 2019/10/28 14:44:47 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/minilibx/mlx.h"
# define HEIGHT 720
# define WIDTH 1080



typedef struct	s_mlx
{
	void	*ptr;
	void	*window;
	int		*img_data;
	void	*img_ptr;
	int		img_bpp;
	int		img_endian;
	int		img_size_l;
}				t_mlx;

typedef struct	s_pixel
{
	int		pr;
	int		pi;
	int		newr;
	int		newi;
	int		oldr;
	int		oldi;
	int		zoom;
	double		movex;
	double		movey;
	int		maxi;
}				t_pixel;

typedef struct	s_var
{
	t_mlx	mlx;
	t_pixel	pixel;
	char	*name;
}				t_var;

void	initvar(t_var *var);
void	fractol(t_var *var);
void	mandelbrot(t_var *var);

#endif