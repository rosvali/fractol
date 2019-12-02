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

# include <stdio.h>
# include <math.h>
# include "../lib/libft/libft.h"
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

// typedef struct	s_px
// {
// 	int			cx;
// 	int			cy;
// 	int			zx;
// 	int			zy;
// 	int			zoom;
// 	int			tmp;
// 	int			i;
// }				t_px;

typedef struct	s_var
{
	t_mlx	mlx;
	int		x;
	int		y;
	int		cx;
	int		cy;
	int		zx;
	int		zy;
	int		zoom;
	int		tmp;
	int		i;
	int		maxi;
	char	*name;
}				t_var;

void	initvar(t_var *var);
void	fractol(t_var *var);
void	mandelbrot(t_var *var);
int		keyhook(int keycode, t_var *var);

#endif