/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:00:44 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/24 14:10:35 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_dir_plane_n(t_var *var)
{
	var->dirX = 0;
	var->dirY = -1;
	var->planeX = 0.66;
	var->planeY = 0;
}

void	set_dir_plane_s(t_var *var)
{
	var->dirX = 0;
	var->dirY = 1;
	var->planeX = -0.66;
	var->planeY = 0;
}

void	set_dir_plane_w(t_var *var)
{
	var->dirX = -1;
	var->dirY = 0;
	var->planeX = 0;
	var->planeY = -0.66;
}

void	set_dir_plane_e(t_var *var)
{
	var->dirX = 1;
	var->dirY = 0;
	var->planeX = 0;
	var->planeY = 0.66;
}
