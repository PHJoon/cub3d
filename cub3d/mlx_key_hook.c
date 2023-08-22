/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:14:44 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/22 14:01:15 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	key_hook_sub(int keycode, t_var *var)
{
	if (keycode == KEY_A)
		key_move_left(var);
	if (keycode == KEY_W)
		key_move_forward(var);
	if (keycode == KEY_S)
		key_move_backward(var);
	if (keycode == KEY_D)
		key_move_right(var);
	if (keycode == KEY_LEFT)
		key_rotate_left(var);
	if (keycode == KEY_RIGHT)
		key_rotate_right(var);
	if (keycode == ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

static int	x_button_click(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}

void	 key_hook_main(t_var *var)
{
	mlx_hook(var->win, 17, 0, &x_button_click, var);
	mlx_hook(var->win, 2, 0, &key_hook_sub, var);
}
