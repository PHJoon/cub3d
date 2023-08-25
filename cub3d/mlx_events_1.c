/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:13:43 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/25 14:21:10 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	key_move_left(t_var *var)
{
	if (var->info->map[(int)(var->pos_y - var->plane_y \
		* MOV_SPEED)][(int)(var->pos_x)] == '0')
		var->pos_y -= var->plane_y * MOV_SPEED;
	if (var->info->map[(int)(var->pos_y)][(int)(var->pos_x - var->plane_x \
		* MOV_SPEED)] == '0')
		var->pos_x -= var->plane_x * MOV_SPEED;
}

void	key_move_right(t_var *var)
{
	if (var->info->map[(int)(var->pos_y + var->plane_y \
		* MOV_SPEED)][(int)(var->pos_x)] == '0')
		var->pos_y += var->plane_y * MOV_SPEED;
	if (var->info->map[(int)(var->pos_y)][(int)(var->pos_x + var->plane_x \
		* MOV_SPEED)] == '0')
		var->pos_x += var->plane_x * MOV_SPEED;
}

void	key_move_forward(t_var *var)
{
	if (var->info->map[(int)(var->pos_y + var->dir_y \
		* MOV_SPEED)][(int)(var->pos_x)] == '0')
		var->pos_y += var->dir_y * MOV_SPEED;
	if (var->info->map[(int)(var->pos_y)][(int)(var->pos_x + var->dir_x \
		* MOV_SPEED)] == '0')
		var->pos_x += var->dir_x * MOV_SPEED;
}

void	key_move_backward(t_var *var)
{
	if (var->info->map[(int)(var->pos_y - var->dir_y \
		* MOV_SPEED)][(int)(var->pos_x)] == '0')
		var->pos_y -= var->dir_y * MOV_SPEED;
	if (var->info->map[(int)(var->pos_y)][(int)(var->pos_x - var->dir_x \
		* MOV_SPEED)] == '0')
		var->pos_x -= var->dir_x * MOV_SPEED;
}
