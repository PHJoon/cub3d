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

static int	key_hook_press(int keycode, t_var *var)
{
	if (keycode == KEY_A)
		var->keys[A] = 1;
	if (keycode == KEY_W)
		var->keys[W] = 1;
	if (keycode == KEY_S)
		var->keys[S] = 1;
	if (keycode == KEY_D)
		var->keys[D] = 1;
	if (keycode == KEY_LEFT)
		var->keys[LEFT] = 1;
	if (keycode == KEY_RIGHT)
		var->keys[RIGHT] = 1;
	if (keycode == ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

static int	key_hook_release(int keycode, t_var *var)
{
	if (keycode == KEY_A)
		var->keys[A] = 0;
	if (keycode == KEY_W)
		var->keys[W] = 0;
	if (keycode == KEY_S)
		var->keys[S] = 0;
	if (keycode == KEY_D)
		var->keys[D] = 0;
	if (keycode == KEY_LEFT)
		var->keys[LEFT] = 0;
	if (keycode == KEY_RIGHT)
		var->keys[RIGHT] = 0;
	return (0);
}

static int	x_button_click(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}

void	key_hook_main(t_var *var)
{
	mlx_hook(var->win, 17, 0, &x_button_click, var);
	mlx_hook(var->win, 2, 1L<<0, &key_hook_press, var);
	mlx_hook(var->win, 3, 1L<<1, &key_hook_release, var);
}
