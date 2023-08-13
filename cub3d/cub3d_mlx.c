/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:41:47 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/08 18:58:51 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void my_mlx_pixel_put(t_var *var, int x, int y, int color)
{
    char *dst;

    dst = var->addr + (y * var->line_l + x * (var->bpp / 8));
    *(unsigned int *)dst = color;
}

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

int get_wall_color(t_var *var)
{
    int color;

    color = 0;
    if (var->info->map[var->mapY][var->mapX] == '1')
    {
        if (var->side == 0)
        {
            // east
            color = 0xAAB9FF;
            // west
            if (var->rayDirX > 0)
                color = 0xE6FFE6;
        }
        else
        {
            // south
            color = 0xFF8E99;
            // north
            if (var->rayDirY < 0)
                color = 0xFF9614;
        }
    }
    return (color);
}

void draw_wall(t_var *var, int x)
{
    int lineHeight;
    int color;

    lineHeight = (int)(HEIGHT / var->perpWallDist);

    int drawStart = -lineHeight / 2 + HEIGHT / 2;
    if (drawStart < 0)
        drawStart = 0;

    int drawEnd = lineHeight / 2 + HEIGHT / 2;
    if (drawEnd >= HEIGHT)
        drawEnd = HEIGHT - 1;

    color = get_wall_color(var);

    int y = drawStart;
    while (y <= drawEnd)
    {
        my_mlx_pixel_put(var, x, y, color);
        y++;
    }
}

// map 그리기
void draw_map(t_var *var)
{
    int x;

    x = -1;
    while (++x < WIDTH)
    {
        set_camera_raydir(var, x);
        calc_step_dir(var);
        calc_wall_hit(var);
        draw_wall(var, x);
    }
}

int	start_mlx(t_var *var)
{
	draw_fc(var);
	draw_map(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	return (0);
}
