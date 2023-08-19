/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joon-lee <joon-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:13:53 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/13 14:13:54 by joon-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    key_rotate_left(t_var *var)
{
    double  past_dirx;
    double  past_planex;

    past_dirx = var->dirX;
	past_planex = var->planeX;
    var->dirX = var->dirX * cos(ROT_SPEED) - var->dirY * sin(ROT_SPEED);
	var->dirY = past_dirx * sin(ROT_SPEED) + var->dirY * cos(ROT_SPEED);
    var->planeX = var->planeX * cos(ROT_SPEED) - var->planeY * sin(ROT_SPEED);
    var->planeY = past_planex * sin(ROT_SPEED) + var->planeY * cos(ROT_SPEED);
}

void    key_rotate_right(t_var *var)
{
    double  past_dirx;
    double  past_planex;

    past_dirx = var->dirX;
	past_planex = var->planeX;
    var->dirX = var->dirX * cos(-1 * ROT_SPEED) - var->dirY * sin(-1 * ROT_SPEED);
	var->dirY = past_dirx * sin(-1 * ROT_SPEED) + var->dirY * cos(-1 * ROT_SPEED);
    var->planeX = var->planeX * cos(-1 * ROT_SPEED) - var->planeY * sin(-1 * ROT_SPEED);
    var->planeY = past_planex * sin(-1 * ROT_SPEED) + var->planeY * cos(-1 * ROT_SPEED);
}
