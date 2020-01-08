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
# define HEIGHT 1000
# define WIDTH 1000

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

typedef struct	s_var
{
	t_mlx	mlx;
	double	x_off;
	double	y_off;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
	double	tmp;
	int		i;
	int		maxi;
	char	*name;
}				t_var;

/*
** burningship.c
*/
void			burningship(t_var *var);
void			burningship_algo(t_var *var);

/*
** draw.c
*/
double			ft_abs(double nbr);
void			black(t_var *var, int x, int y);
void			color(t_var *vari, int x, int y);
void			draw(t_var *var);

/*
** fractol.c
*/
void			init_var(t_var *var);
void			init_off(t_var *var);
void			fractol(t_var *var);

/*
** hook.c
*/
int				key_hook(int keycode, t_var *var);
int				loop_hook(t_var *var);
int				mouse_hook(int button, int x, int y, t_var *var);
/*
** julia.c
*/
void			julia(t_var *var);
void			julia_algo(t_var *var);

/*
** mandelbrot.c
*/
void			mandelbrot(t_var *var);
void			mandelbrot_algo(t_var *var);

#endif
