/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:41:47 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/25 14:22:23 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_camera_raydir(t_var *var, int x)
{
	var->camera_x = 2 * x / (double)WIDTH - 1;
	var->raydir_x = var->dir_x + var->plane_x * var->camera_x;
	var->raydir_y = var->dir_y + var->plane_y * var->camera_x;
	var->map_x = (int)var->pos_x;
	var->map_y = (int)var->pos_y;
	var->delta_dist_x = fabs(1 / var->raydir_x);
	var->delta_dist_y = fabs(1 / var->raydir_y);
}

void	calc_step_dir(t_var *var)
{
	if (var->raydir_x < 0)
	{
		var->step_x = -1;
		var->side_dist_x = (var->pos_x - var->map_x) * var->delta_dist_x;
	}
	else
	{
		var->step_x = 1;
		var->side_dist_x = (var->map_x + 1.0 - var->pos_x) * var->delta_dist_x;
	}
	if (var->raydir_y < 0)
	{
		var->step_y = -1;
		var->side_dist_y = (var->pos_y - var->map_y) * var->delta_dist_y;
	}
	else
	{
		var->step_y = 1;
		var->side_dist_y = (var->map_y + 1.0 - var->pos_y) * var->delta_dist_y;
	}
}

void	calc_wall_hit(t_var *var)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (var->side_dist_x < var->side_dist_y)
		{
			var->side_dist_x += var->delta_dist_x;
			var->map_x += var->step_x;
			var->side = 0;
		}
		else
		{
			var->side_dist_y += var->delta_dist_y;
			var->map_y += var->step_y;
			var->side = 1;
		}
		if (var->info->map[var->map_y][var->map_x] == '1')
			hit = 1;
	}
	if (var->side == 0)
		var->perp_wall_dist = var->side_dist_x - var->delta_dist_x;
	else
		var->perp_wall_dist = var->side_dist_y - var->delta_dist_y;
}
