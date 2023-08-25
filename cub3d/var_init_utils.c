/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:00:44 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/25 14:21:10 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_dir_plane_n(t_var *var)
{
	var->dir_x = 0;
	var->dir_y = -1;
	var->plane_x = 0.66;
	var->plane_y = 0;
}

void	set_dir_plane_s(t_var *var)
{
	var->dir_x = 0;
	var->dir_y = 1;
	var->plane_x = -0.66;
	var->plane_y = 0;
}

void	set_dir_plane_w(t_var *var)
{
	var->dir_x = -1;
	var->dir_y = 0;
	var->plane_x = 0;
	var->plane_y = -0.66;
}

void	set_dir_plane_e(t_var *var)
{
	var->dir_x = 1;
	var->dir_y = 0;
	var->plane_x = 0;
	var->plane_y = 0.66;
}
