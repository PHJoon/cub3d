/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:07:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 02:09:05 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void get_dir_plane(t_var *var, t_info *info)
{
    if (info->player_dir == 'N')
    {
        var->dirX = 0;
        var->dirY = -1;
        var->planeX = -0.66;
        var->planeY = 0;
    }
    if (info->player_dir == 'S')
    {
        var->dirX = 0;
        var->dirY = 1;
        var->planeX = 0.66;
        var->planeY = 0;
    }
    if (info->player_dir == 'W')
    {
        var->dirX = -1;
        var->dirY = 0;
        var->planeX = 0;
        var->planeY = -0.66;
    }
    if (info->player_dir == 'E')
    {
        var->dirX = 1;
        var->dirY = 0;
        var->planeX = 0;
        var->planeY = 0.66;
    }
}

void var_init(t_var *var, t_info *info)
{
    var->info = info;
    var->posX = (double)info->player_x;
    var->posY = (double)info->player_y;
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
