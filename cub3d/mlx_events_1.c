/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joon-lee <joon-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:13:43 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/13 14:13:46 by joon-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	key_move_left(t_var *var)
{
	if (var->info->map[(int)(var->posY - var->dirY * MOV_SPEED)]\
		[(int)var->posX] == '0')
		var->posX -= var->dirY * MOV_SPEED;
	if (var->info->map[(int)var->posY]\
		[(int)(var->posX + var->dirX * MOV_SPEED)] == '0')
		var->posY += var->dirX * MOV_SPEED;
}

void    key_move_right(t_var *var)
{
	if (var->info->map[(int)(var->posY + var->dirY * MOV_SPEED)]\
		[(int)var->posX] == '0')
    	var->posX += var->dirY * MOV_SPEED;
	if (var->info->map[(int)var->posY]\
		[(int)(var->posX - var->dirX * MOV_SPEED)] == '0')
    	var->posY -= var->dirX * MOV_SPEED;
}

void    key_move_forward(t_var *var)
{
	if (var->info->map[(int)(var->posY + var->dirY * MOV_SPEED)]\
		[(int)var->posX] == '0')
		var->posX += var->dirX * MOV_SPEED;
	if (var->info->map[(int)var->posY]\
		[(int)(var->posX + var->dirX * MOV_SPEED)] == '0')
		var->posY += var->dirY * MOV_SPEED;
}

void    key_move_backward(t_var *var)
{
	if (var->info->map[(int)(var->posY - var->dirY * MOV_SPEED)]\
		[(int)var->posX] == '0')
		var->posX -= var->dirX * MOV_SPEED;
	if (var->info->map[(int)var->posY]\
		[(int)(var->posX - var->dirX * MOV_SPEED)] == '0')
		var->posY -= var->dirY * MOV_SPEED;
}
