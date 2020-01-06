#include "../includes/fractol.h"

int		loop_hook(t_var *var)
{
	draw(var);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.window, var->mlx.img_ptr, 0, 0);
	return (0);
}
 
int		keyhook(int keycode, t_var *var)
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