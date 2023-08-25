/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:16:46 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/25 14:21:53 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	get_wall_color(t_var *var, int dir)
{
	unsigned int	color;
	int				wall_x;
	int				wall_y;
	t_text			text_one;

	wall_x = var->wall_tex_x;
	wall_y = var->wall_tex_y;
	text_one = var->info->text_arr[dir];
	color = *(unsigned int *)(text_one.addr + (wall_y * text_one.line_l + \
			wall_x * (text_one.bpp / 8)));
	return (color);
}

void	calc_text(t_var *var)
{
	if (var->side == 0)
		var->wall_x = var->pos_y + var->perp_wall_dist * var->raydir_y;
	else
		var->wall_x = var->pos_x + var->perp_wall_dist * var->raydir_x;
	var->wall_x -= floor(var->wall_x);
	var->wall_tex_x = (int)(var->wall_x * (double)TEX_WIDTH);
	if ((var->side == 0 && var->raydir_x < 0) || (var->side == 1 && \
		var->raydir_y > 0))
		var->wall_tex_x = TEX_WIDTH - var->wall_tex_x - 1;
	var->step_text = 1.0 * TEX_HEIGHT / (int)(HEIGHT / var->perp_wall_dist);
	var->tex_pos = (var->draw_start - HEIGHT / 2 + (int)(HEIGHT / \
					var->perp_wall_dist) / 2) * var->step_text;
}

void	draw_wall(t_var *var, int x)
{
	unsigned int	color;
	int				y_idx;

	y_idx = var->draw_start;
	while (y_idx < var->draw_end)
	{
		var->wall_tex_y = (int)var->tex_pos;
		var->tex_pos += var->step_text;
		if (var->side == 1 && var->raydir_y < 0)
			color = get_wall_color(var, NO);
		else if (var->side == 1 && var->raydir_y > 0)
			color = get_wall_color(var, SO);
		else if (var->side == 0 && var->raydir_x < 0)
			color = get_wall_color(var, WE);
		else if (var->side == 0 && var->raydir_x > 0)
			color = get_wall_color(var, EA);
		my_mlx_pixel_put(var, x, y_idx, color);
		y_idx++;
	}
}

void	set_draw_unit(t_var *var)
{
	int	lineheight;

	lineheight = (int)(HEIGHT / var->perp_wall_dist);
	var->draw_start = -lineheight / 2 + HEIGHT / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_end = lineheight / 2 + HEIGHT / 2;
	if (var->draw_end >= HEIGHT)
		var->draw_end = HEIGHT - 1;
}
