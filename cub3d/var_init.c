/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:07:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/25 14:22:23 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	get_dir_plane(t_var *var, t_info *info)
{
	if (info->player_dir == 'N')
		set_dir_plane_n(var);
	if (info->player_dir == 'S')
		set_dir_plane_s(var);
	if (info->player_dir == 'W')
		set_dir_plane_w(var);
	if (info->player_dir == 'E')
		set_dir_plane_e(var);
}

void	var_init(t_var *var, t_info *info)
{
	var->info = info;
	var->pos_x = (double)info->player_x + 0.5;
	var->pos_y = (double)info->player_y + 0.5;
	get_dir_plane(var, info);
	var->camera_x = 0;
	var->map_x = 0;
	var->map_y = 0;
	var->side = 0;
	var->raydir_x = 0;
	var->raydir_y = 0;
	var->step_x = 0;
	var->step_y = 0;
	var->side_dist_x = 0;
	var->side_dist_y = 0;
	var->delta_dist_x = 0;
	var->delta_dist_x = 0;
	var->perp_wall_dist = 0;
}
