/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:26:16 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/22 14:02:13 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	mlx_total_init(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, WIDTH, HEIGHT, "cub3d");
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	var->addr = mlx_get_data_addr(var->img, &var->bpp, \
					&var->line_l, &var->endian);
	if (init_xpm_files(var) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static void	err_msg_n_exit(void)
{
	ft_putendl_fd("Error\n", STDERR_FILENO);
	exit(1);
}

static void	malloc_var(t_info *info)
{
	info->dir_flags = (int *)malloc(sizeof(int) * 6);
	if (!info->dir_flags)
		err_msg_n_exit();
	info->dir = (char **)malloc(sizeof(char *) * 4);
	if (!info->dir)
		err_msg_n_exit();
	info->fc = (char **)malloc(sizeof(char *) * 6);
	if (!info->fc)
		err_msg_n_exit();
	info->fc_num = (int *)malloc(sizeof(int) * 6);
	if (!info->fc_num)
		err_msg_n_exit();
	info->text_arr = (t_text *)malloc(sizeof(t_text) * 4);
	if (!info->text_arr)
		err_msg_n_exit();
}

static void	init_text(t_text *text)
{
	text->img = NULL;
	text->addr = NULL;
	text->bpp = 0;
	text->line_l = 0;
	text->endian = 0;
}

void	init_info(t_info *info)
{
	int	i;

	i = -1;
	malloc_var(info);
	while (++i < 6)
	{
		info->dir_flags[i] = 0;
		info->fc[i] = 0;
		info->fc_num[i] = 0;
		if (i < 4)
		{
			info->dir[i] = 0;
			init_text(&info->text_arr[i]);
		}
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
}
