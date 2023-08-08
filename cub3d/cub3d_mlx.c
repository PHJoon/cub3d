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

void	my_mlx_pixel_put(t_var *var, int x, int y, int color)
{
	char	*dst;

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

// map 그리기
void draw_map(t_var *var)
{
    int x;
    double  cameraX;
    double  rayDirX;
    double  rayDirY;

    int stepX;
    int stepY;

    int hit;
    int side;
    
    int lineHeight;

    x = -1;
    while (++x < WIDTH)
    {
        cameraX = 2 * x / (double)WIDTH - 1;
        rayDirX = var->dirX + var->planeX * cameraX;
        rayDirY = var->dirY + var->planeY * cameraX;

        // printf("rayDirX: %f\n", rayDirX);
        // printf("rayDirY: %f\n", rayDirY);
        // exit(0);

        var->mapX = (int)var->posX;
        var->mapY = (int)var->posY;

        var->deltaDistX = fabs(1 / rayDirX);
        var->deltaDistY = fabs(1 / rayDirY);

        // printf("%f, %f\n", var->deltaDistX, var->deltaDistY);
        // exit(0);

        if (rayDirX < 0)
        {
            stepX = -1;
            var->sideDistX = (var->posX - var->mapX) * var->deltaDistX;   
        }
        else
        {
            stepX = 1;
            var->sideDistX = (var->mapX + 1.0 - var->posX) * var->deltaDistX;            
        }
        if (rayDirY < 0)
        {
            stepY = 1;
            var->sideDistY = (var->posY - var->mapY) * var->deltaDistY;
        }
        else
        {
            stepY = -1;
            var->sideDistY = (var->mapY + 1.0 - var->posY) * var->deltaDistY;
        }

        // printf("stepX: %d stepY: %d\n", stepX, stepY);
        // printf("sidedistX: %f sideDistY: %f\n", var->sideDistX, var->sideDistY);
        // exit(0);

        hit = 0;
        while (hit == 0)
        {
            if (var->sideDistX < var->sideDistX)
            {
                var->sideDistX += var->deltaDistX;
                var->mapX += stepX;
                side = 0;
            }
            else
            {
                var->sideDistY += var->deltaDistY;
                var->mapY += stepY;
                side = 1;
            }
            if (!ft_strncmp(&var->info->map[var->mapX][var->mapY], "1", 1)) 
                hit = 1;
        }

        // printf("mapX: %d, mapY: %d\n", var->mapX, var->mapY);
        // exit(0);

        if (side == 0)
			// var->perpWallDist = (var->mapX - var->posX + (1 - stepX) / 2) / rayDirX;
			var->perpWallDist = var->sideDistX - var->deltaDistX;
        else
            // var->perpWallDist = (var->mapY - var->posY + (1 - stepY) / 2) / rayDirY;
            var->perpWallDist = var->sideDistY - var->deltaDistY;
        
        printf("%f\n", var->perpWallDist);
        // exit(0);
        lineHeight = (int)(HEIGHT / var->perpWallDist);
        
        int drawStart = -lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;

        int drawEnd = lineHeight / 2 + HEIGHT / 2;
        if (drawEnd >= HEIGHT)
            drawEnd = HEIGHT - 1;

        int color;

        // n 111111
        // s 222222
        // w 333333
        // e 444444

        if (rayDirX < 0 && rayDirY < 0)
        {
            if (side == 0)
                // s
                color = 222222;
            else
                // w
                color = 333333;
        }
        if (rayDirX < 0 && rayDirY > 0)
        {
            if (side == 0)
                // n
                color = 111111;
            else
                // w
                color = 333333;
        }
        if (rayDirX > 0 && rayDirY < 0)
        {
            if (side == 0)
                // s
                color = 222222;
            else
                // e
                color = 444444;
        }
        if (rayDirX > 0 && rayDirY > 0)
        {
            if (side == 0)
                // n
                color = 111111;
            else
                // e
                color = 444444;
        }

        // if (side == 1)
            // color = color / 10;
        int y = drawStart;
        while (y <= drawEnd)
        {
            my_mlx_pixel_put(var, x, y, color);
            y++;
        }
    }
}


static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// 천장 바닥 색칠하기
void    draw_floor_ceiling(t_var *var)
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
                my_mlx_pixel_put(var, x, y, create_trgb(80, 80, 80, 80));
            else
                my_mlx_pixel_put(var, x, y, create_trgb(40, 40, 40, 40));
        }
    }
}


void    start_mlx(t_var *var)
{
    var->mlx = mlx_init();
    var->win = mlx_new_window(var->mlx, WIDTH, HEIGHT, "cub3d");
    var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
    var->addr = mlx_get_data_addr(var->img, &var->bpp, \
    &var->line_l, &var->endian);

    // 천장 바닥 먼저 그리기
    // draw_floor_ceiling(var);
    // draw_map
    // draw_map(var);

    draw_mini(var);

    // 매번 이미지 찍어주기
    mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
    
    
    // mlx key hook 추가
    // mlx_key_hook(var->win, &keyboard_event, (void *)var);

    mlx_loop(var->mlx);
}
