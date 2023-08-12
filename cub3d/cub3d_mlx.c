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

// 키보드 이벤트 회전행렬 적용
int keyboard_event(int keycode, t_var *var)
{
    (void)var;
    if (keycode == KEY_A)
    {
    }
    if (keycode == KEY_S)
    {
    }
    if (keycode == KEY_D)
    {
    }
    if (keycode == KEY_W)
    {
    }
    if (keycode == KEY_LEFT)
    {
    }
    if (keycode == KEY_RIGHT)
    {
    }
    if (keycode == ESC)
        exit(0);
    return (0);
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

static int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

// 천장 바닥 색칠하기
void draw_floor_ceiling(t_var *var)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            if (y <= HEIGHT / 2)
                my_mlx_pixel_put(var, x, y, create_trgb(0, 255, 0, 80));
            else
                my_mlx_pixel_put(var, x, y, create_trgb(0, 255, 255, 40));
        }
    }
}

void start_mlx(t_var *var)
{
    var->mlx = mlx_init();
    var->win = mlx_new_window(var->mlx, WIDTH, HEIGHT, "cub3d");
    var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
    var->addr = mlx_get_data_addr(var->img, &var->bpp,
                                  &var->line_l, &var->endian);

    // 천장 바닥 먼저 그리기
    draw_floor_ceiling(var);

    // draw_map
    draw_map(var);

    // 매번 이미지 찍어주기
    mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);

    // mlx key hook 추가
    // mlx_key_hook(var->win, &keyboard_event, (void *)var);

    mlx_loop(var->mlx);
}
