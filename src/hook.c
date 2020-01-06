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

	r = (var->i * 255) / (var->maxi * 1);
	g = (var->i * 255) / (var->maxi * 1);
	b = (var->i * 255) / (var->maxi * 1);
	var->mlx.img_data[((int)(y * WIDTH + (int)x)) + 2] = r;
	var->mlx.img_data[(((int)y * WIDTH + (int)x)) + 1] = g;
	var->mlx.img_data[((int)(y * WIDTH + (int)x))] = b;
}

int		loop_hook(t_var *var)
{
	draw(var);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.window, var->mlx.img_ptr, 0, 0);
	return (0);
}
 
int		key_hook(int keycode, t_var *var)
{
	//printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if(keycode == 6)
		var->zoom += 0.1;
	else if (keycode == 7)
		var->zoom -= 0.1;
	else if (keycode == 2 || keycode == 124)
		var->x_off += 0.1;
	else if (keycode == 0 || keycode == 123)
		var->x_off -= 0.1;
	else if (keycode == 13 || keycode == 126)
		var->y_off -= 0.1;
	else if (keycode == 1 || keycode == 125)
		var->y_off += 0.1;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_var *var)
{
	if (button == 4)
	{
		var->zoom -= 1;
		var->xmouse = x;
		var->ymouse = y;
	}
	if (button == 5)
	{
		var->zoom += 1;
		var->xmouse = x;
		var->ymouse = y;
	}
	return (0);
}