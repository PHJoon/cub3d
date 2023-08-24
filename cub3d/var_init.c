/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:07:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/24 13:44:18 by hyungjpa         ###   ########.fr       */
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
	var->posX = (double)info->player_x + 0.5;
	var->posY = (double)info->player_y + 0.5;
	get_dir_plane(var, info);
	var->cameraX = 0;
	var->mapX = 0;
	var->mapY = 0;
	var->side = 0;
	var->rayDirX = 0;
	var->rayDirY = 0;
	var->stepX = 0;
	var->stepY = 0;
	var->sideDistX = 0;
	var->sideDistY = 0;
	var->deltaDistX = 0;
	var->deltaDistX = 0;
	var->perpWallDist = 0;
}
