/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_fc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:16:00 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/24 14:36:11 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	color_decode(int *col, int flag)
{
	if (flag == 0)
		return (col[0] << 16 | col[1] << 8 | col[2]);
	else
		return (col[3] << 16 | col[4] << 8 | col[5]);
}

static void	color_atoi(t_var *var)
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
	if (var->info->fc_num)
		free(var->info->fc_num);
	var->info->fc_num = color_pal;
}

static int	color_grad(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(((color1 >> 16) & 0xFF) * (1 - t) + \
					((color2 >> 16) & 0xFF) * t);
	g = (int)(((color1 >> 8) & 0xFF) * (1 - t) + \
					((color2 >> 8) & 0xFF) * t);
	b = (int)((color1 & 0xFF) * (1 - t) + (color2 & 0xFF) * t);
	return ((r << 16) | (g << 8) | b);
}

void	draw_fc(t_var *var)
{
	int		idx_h;
	int		idx_w;
	double	cur_idx;

	color_atoi(var);
	idx_h = 0;
	while (idx_h < HEIGHT)
	{
		if (idx_h >= HEIGHT / 2)
			cur_idx = (double)(idx_h - (HEIGHT / 2)) / (HEIGHT / 2);
		else
			cur_idx = (double)idx_h / (HEIGHT / 2);
		idx_w = 0;
		while (idx_w < WIDTH)
		{
			if (idx_h < HEIGHT / 2)
				my_mlx_pixel_put(var, idx_w, idx_h, \
			color_grad(color_decode(var->info->fc_num, 0), 0x000000, cur_idx));
			else
				my_mlx_pixel_put(var, idx_w, idx_h, \
			color_grad(0x000000, color_decode(var->info->fc_num, 1), cur_idx));
			idx_w++;
		}
		idx_h++;
	}
}
