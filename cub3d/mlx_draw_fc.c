/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_fc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joon-lee <joon-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:16:00 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/13 14:16:02 by joon-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static  int color_decode(int *col, int flag)
{
	if (flag == 0)
		return (col[0] << 16 | col[1] << 8 | col[2]);
	else
		return (col[3]  << 16 | col[4] << 8 | col[5]);
}

static void color_atoi(t_var *var)
{
	int	*color_pal;

	color_pal = (int *)malloc(sizeof(int) * 6);
	if (!color_pal)
		exit(1);
	color_pal[0] = ft_atoi(var->info->fc[0]);
	color_pal[1] = ft_atoi(var->info->fc[1]);
	color_pal[2] = ft_atoi(var->info->fc[2]);
	color_pal[3] = ft_atoi(var->info->fc[3]);
	color_pal[4] = ft_atoi(var->info->fc[4]);
	color_pal[5] = ft_atoi(var->info->fc[5]);
	var->info->fc_num = color_pal;
}

static int color_grad(int color1, int color2, double t) {
    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;

    int r2 = (color2 >> 16) & 0xFF;
    int g2 = (color2 >> 8) & 0xFF;
    int b2 = color2 & 0xFF;

    int r = (int)(r1 * (1 - t) + r2 * t);
    int g = (int)(g1 * (1 - t) + g2 * t);
    int b = (int)(b1 * (1 - t) + b2 * t);

    return ((r << 16) | (g << 8) | b);
}

void draw_fc(t_var *var)
{
    int idx_h;
    int idx_w;
	double	cur_idx;
	int	cur_floor;
	int	cur_ceiling;

    color_atoi(var);
    idx_h = 0;
    while (idx_h < HEIGHT) {
		if (idx_h >= HEIGHT / 2)
			cur_idx = (double)(idx_h - (HEIGHT / 2)) / (HEIGHT / 2);
		else
			cur_idx = (double)idx_h / (HEIGHT / 2);
		idx_w = 0;
        cur_floor = color_grad(0x000000, color_decode(var->info->fc_num, 0), cur_idx);
        cur_ceiling = color_grad(color_decode(var->info->fc_num, 1), 0x000000, cur_idx);
        while (idx_w < WIDTH) {
            if (idx_h < HEIGHT / 2)
                my_mlx_pixel_put(var, idx_w, idx_h, cur_ceiling);
            else
                my_mlx_pixel_put(var, idx_w, idx_h, cur_floor);
            idx_w++;
        }
        idx_h++;
    }
}
