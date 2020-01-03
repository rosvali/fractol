#include "../includes/fractol.h"

void	black(t_var *var, int x, int y)
{
	var->mlx.img_data[((int)(y * WIDTH + (int)x)) + 2] = 0;
	var->mlx.img_data[(((int)y * WIDTH + (int)x)) + 1] = 0;
	var->mlx.img_data[(((int)y * WIDTH + (int)x))] = 0;
}

void	color(t_var *var, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (var->i * 255) / var->maxi;
	g = (var->i * 255) / var->maxi;
	b = (var->i * 255) / var->maxi;
	var->mlx.img_data[((int)(y * WIDTH + (int)x)) + 2] = r;
	var->mlx.img_data[(((int)y * WIDTH + (int)x)) + 1] = g;
	var->mlx.img_data[((int)(y * WIDTH + (int)x))] = b;
}

void	mandelbrot(t_var *var)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	initvar(var);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			var->cx = (x - WIDTH) / (var->zoom * WIDTH) + var->x_off;
			var->cy = (y - HEIGHT) / (var->zoom * HEIGHT) + var->y_off;
			var->i = 0;
			var->zx = 0;
			var->zy = 0;
			while (var->zx * var->zx + var->zy * var->zy < 4 && var->i < var->maxi)
			{
				var->tmp = var->zx * var->zx - var->zy * var->zy + var->cx;
				var->zy = var->zx * var->zy + var->zx * var->zy + var->cy;
				var->zx = var->tmp;
				var->i = var->i + 1;
			}
			if (var->i == var->maxi)
				black(var, x, y);
			else
				color(var, x, y);
			y++;
		}
		x++;
	}
}
