/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:13:53 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/25 14:24:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	key_rotate_left(t_var *var)
{
	double	past_dir_x;
	double	past_plane_x;

	past_dir_x = var->dir_x;
	past_plane_x = var->plane_x;
	var->dir_x = var->dir_x * cos(-1 * ROT_SPEED) - var->dir_y \
				* sin(-1 * ROT_SPEED);
	var->dir_y = past_dir_x * sin(-1 * ROT_SPEED) + var->dir_y \
				* cos(-1 * ROT_SPEED);
	var->plane_x = var->plane_x * cos(-1 * ROT_SPEED) - var->plane_y \
				* sin(-1 * ROT_SPEED);
	var->plane_y = past_plane_x * sin(-1 * ROT_SPEED) + var->plane_y \
				* cos(-1 * ROT_SPEED);
}

void	key_rotate_right(t_var *var)
{
	double	past_dir_x;
	double	past_plane_x;

	past_dir_x = var->dir_x;
	past_plane_x = var->plane_x;
	var->dir_x = var->dir_x * cos(ROT_SPEED) - var->dir_y * sin(ROT_SPEED);
	var->dir_y = past_dir_x * sin(ROT_SPEED) + var->dir_y * cos(ROT_SPEED);
	var->plane_x = var->plane_x * cos(ROT_SPEED) - var->plane_y \
				* sin(ROT_SPEED);
	var->plane_y = past_plane_x * sin(ROT_SPEED) + var->plane_y \
				* cos(ROT_SPEED);
}
