/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:13:43 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/19 02:01:02 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	prevent_wall_crash(double rayDirX, double rayDirY, double *x, double *y)
{
	if (rayDirX < 0)
		*x = 0.5;
	else
		*x = -0.5;

	if (rayDirY < 0)
		*y = 0.5;
	else
		*y = -0.5;
}


void	key_move_left(t_var *var)
{
	double	x;
	double	y;

	prevent_wall_crash(var->rayDirX, var->rayDirY, &x, &y);
	if (var->info->map[(int)(var->posY - var->dirY * MOV_SPEED)]\
		[(int)(var->posX + x)] == '0')
		var->posX -= var->dirY * MOV_SPEED;
	if (var->info->map[(int)(var->posY + y)]\
		[(int)(var->posX + var->dirX * MOV_SPEED)] == '0')
		var->posY += var->dirX * MOV_SPEED;
}

void    key_move_right(t_var *var)
{
	double x;
	double y;

	prevent_wall_crash(var->rayDirX, var->rayDirY, &x, &y);
	if (var->info->map[(int)(var->posY + var->dirY * MOV_SPEED)]\
		[(int)(var->posX - x)] == '0')
    	var->posX += var->dirY * MOV_SPEED;
	if (var->info->map[(int)(var->posY - y)]\
		[(int)(var->posX - var->dirX * MOV_SPEED)] == '0')
    	var->posY -= var->dirX * MOV_SPEED;
}

void    key_move_forward(t_var *var)
{
	double x;
	double y;

	prevent_wall_crash(var->rayDirX, var->rayDirY, &x, &y);
	if (var->info->map[(int)(var->posY + var->dirY * MOV_SPEED)]\
		[(int)(var->posX - x)] == '0')
		var->posX += var->dirX * MOV_SPEED;
	if (var->info->map[(int)(var->posY - y)]\
		[(int)(var->posX + var->dirX * MOV_SPEED)] == '0')
		var->posY += var->dirY * MOV_SPEED;
}

void    key_move_backward(t_var *var)
{
	double x;
	double y;

	prevent_wall_crash(var->rayDirX, var->rayDirY, &x, &y);
	if (var->info->map[(int)(var->posY - var->dirY * MOV_SPEED)]\
		[(int)(var->posX + x)] == '0')
		var->posX -= var->dirX * MOV_SPEED;
	if (var->info->map[(int)(var->posY + y)]\
		[(int)(var->posX - var->dirX * MOV_SPEED)] == '0')
		var->posY -= var->dirY * MOV_SPEED;
}
