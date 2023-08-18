/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cub3d_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:11:31 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 02:15:25 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void my_mlx_pixel_put(t_var *var, int x, int y, int color)
{
    char *dst;

    dst = var->addr + (y * var->line_l + x * (var->bpp / 8));
    *(unsigned int *)dst = color;
}

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

int start_mlx(t_var *var)
{
    draw_fc(var);
    draw_map(var);
    mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
    return (0);
}