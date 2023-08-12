#include "main.h"

static int	escape_key_click(int keycode, t_var *var)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (1);
}

static int	x_button_click(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}

void	 key_hook_main(t_var *var)
{
	mlx_hook(var->win, 2, 0, escape_key_click, var->mlx);
	mlx_hook(var->win, 17, 0, x_button_click, var->mlx);
}