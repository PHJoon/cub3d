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

unsigned int get_wall_color(t_var *var, int dir)
{
    unsigned int 	color;
	int 	        wall_x;
	int 	        wall_y;
	t_text          text_one;

	wall_x = var->wall_tex_x;
	wall_y = var->wall_tex_y;
	text_one = var->info->text_arr[dir];
	color = *(unsigned int *)(text_one.addr + (wall_y * text_one.line_l + wall_x * (text_one.bpp / 8)));
    return (color);
}

void    calc_text(t_var *var)
{
    if (var->side == 0)
        var->wall_x = var->posY + var->perpWallDist * var->rayDirY;
    else
        var->wall_x = var->posX + var->perpWallDist * var->rayDirX;
    var->wall_x -= floor(var->wall_x);
    var->wall_tex_x = (int)(var->wall_x * (double)TEX_WIDTH);
    if ((var->side == 0 && var->rayDirX > 0)
        || (var->side == 1 && var->rayDirY < 0))
        var->wall_tex_x = TEX_WIDTH - var->wall_tex_x - 1;
    var->step_text = 1.0 * TEX_HEIGHT / (int)(HEIGHT / var->perpWallDist);
    var->tex_pos = (var->drawStart - HEIGHT / 2 + (int)(HEIGHT / var->perpWallDist) / 2) * var->step_text;
}

void draw_wall(t_var *var, int x)
{
    unsigned int	color;
	int	            y_idx;

    y_idx = var->drawStart;
    while (y_idx < var->drawEnd)
    {
		var->wall_tex_y = (int)var->tex_pos;
        var->tex_pos += var->step_text;
		if (var->side == 0 && var->rayDirX > 0)
			color = get_wall_color(var, NO);
		else if (var->side == 0 && var->rayDirX < 0)
			color = get_wall_color(var, SO);
		else if (var->side == 1 && var->rayDirY > 0)
			color = get_wall_color(var, WE);
		else if (var->side == 1 && var->rayDirY < 0)
			color = get_wall_color(var, EA);
        my_mlx_pixel_put(var, x, y_idx, color);
        y_idx++;
    }
}

void set_draw_unit(t_var *var)
{
    int lineHeight;

    lineHeight = (int)(HEIGHT / var->perpWallDist);
	var->drawStart = -lineHeight / 2 + HEIGHT / 2;
	if (var->drawStart < 0)
		var->drawStart = 0;
	var->drawEnd = lineHeight / 2 + HEIGHT / 2;
	if (var->drawEnd >= HEIGHT)
		var->drawEnd = HEIGHT - 1;
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
        set_draw_unit(var);
        calc_text(var);
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
