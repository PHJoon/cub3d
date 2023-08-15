/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:26:16 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/08 18:26:28 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	mlx_total_init(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, WIDTH, HEIGHT, "cub3d");
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	var->addr = mlx_get_data_addr(var->img, &var->bpp, \
					&var->line_l, &var->endian);
	init_xpm_files(var);
}

static t_flag malloc_fail_free(t_info *info, int n)
{
    if (n >= 0)
        free(info->dir_flags);
    if (n >= 1)
        free(info->dir);
    if (n >= 2)
        free(info->fc);
    if (n >= 3)
        free(info->fc_num);
    return (FAIL);
}

static t_flag malloc_var(t_info *info)
{
    info->dir_flags = (int *)malloc(sizeof(int) * 6);
    if (!info->dir_flags)
        return (FAIL);
    info->dir = (char **)malloc(sizeof(char *) * 4);
    if (!info->dir)
        return (malloc_fail_free(info, 0));
    info->fc = (char **)malloc(sizeof(char *) * 6);
    if (!info->fc)
        return (malloc_fail_free(info, 1));
    info->fc_num = (int *)malloc(sizeof(int) * 6);
    if (!info->fc_num)
        return (malloc_fail_free(info, 2));
    info->text_arr = (t_text *)malloc(sizeof(t_text) * 4);
    if (!info->text_arr)
        return (malloc_fail_free(info, 3));
    return (SUCCESS);
}

t_flag init_info(t_info *info)
{
    int i;

    i = -1;
    if (malloc_var(info) == FAIL)
        return (FAIL);
    while (++i < 6)
    {
        info->dir_flags[i] = 0;
        info->fc[i] = 0;
        info->fc_num[i] = 0;
        if (i < 4)
            info->dir[i] = 0;
    }
    info->map = NULL;
    info->map_test = NULL;
    info->map_before = NULL;
    info->map_flag = 0;
    info->height = 0;
    info->width = 0;
    info->player_dir = 0;
    info->player_x = 0;
    info->player_y = 0;
    return (SUCCESS);
}

void var_init(t_var *var, t_info *info)
{
    var->info = info;
    var->posX = (double)info->player_x;
    var->posY = (double)info->player_y;

    // 플레이어가 바라보는 방향 벡터 결정
    if (info->player_dir == 'N')
    {
        var->dirX = 0;
        var->dirY = -1;
        var->planeX = -0.66;
        var->planeY = 0;
    }
    if (info->player_dir == 'S')
    {
        var->dirX = 0;
        var->dirY = 1;
        var->planeX = 0.66;
        var->planeY = 0;
    }
    if (info->player_dir == 'W')
    {
        var->dirX = -1;
        var->dirY = 0;
        var->planeX = 0;
        var->planeY = -0.66;
    }
    if (info->player_dir == 'E')
    {
        var->dirX = 1;
        var->dirY = 0;
        var->planeX = 0;
        var->planeY = 0.66;
    }

    var->cameraX = 0;
    var->mapX = 0;
    var->mapY = 0;
    var->side = 0;
    var->rayDirX = 0;
    var->rayDirY = 0;
    var->stepX = 0;
    var->stepY = 0;
    var->sideDistX = 0;
    var->sideDistY = 0;
    var->deltaDistX = 0;
    var->deltaDistX = 0;
    var->perpWallDist = 0;
}
