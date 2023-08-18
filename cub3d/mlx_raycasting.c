/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:41:47 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 02:18:16 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    set_camera_raydir(t_var *var, int x)
{
    var->cameraX = 2 * x / (double)WIDTH - 1;
    var->rayDirX = var->dirX + var->planeX * var->cameraX;
    var->rayDirY = var->dirY + var->planeY * var->cameraX;

    var->mapX = (int)var->posX;
    var->mapY = (int)var->posY;

    var->deltaDistX = fabs(1 / var->rayDirX);
    var->deltaDistY = fabs(1 / var->rayDirY);
}

void    calc_step_dir(t_var *var)
{
    if (var->rayDirX < 0)
    {
        var->stepX = -1;
        var->sideDistX = (var->posX - var->mapX) * var->deltaDistX;
    }
    else
    {
        var->stepX = 1;
        var->sideDistX = (var->mapX + 1.0 - var->posX) * var->deltaDistX;
    }
    if (var->rayDirY < 0)
    {
        var->stepY = -1;
        var->sideDistY = (var->posY - var->mapY) * var->deltaDistY;
    }
    else
    {
        var->stepY = 1;
        var->sideDistY = (var->mapY + 1.0 - var->posY) * var->deltaDistY;
    }
}

void calc_wall_hit(t_var *var)
{
    int hit;

    hit = 0;
    while (hit == 0)
    {
        if (var->sideDistX < var->sideDistY)
        {
            var->sideDistX += var->deltaDistX;
            var->mapX += var->stepX;
            var->side = 0;
        }
        else
        {
            var->sideDistY += var->deltaDistY;
            var->mapY += var->stepY;
            var->side = 1;
        }
        if (var->info->map[var->mapY][var->mapX] == '1')
            hit = 1;
    }
    if (var->side == 0)
        var->perpWallDist = var->sideDistX - var->deltaDistX;
    else
        var->perpWallDist = var->sideDistY - var->deltaDistY;
}
