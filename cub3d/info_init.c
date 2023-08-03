/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:26:16 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/25 18:04:20 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_flag malloc_fail_free(t_info *info, int n)
{
    if (n >= 0)
        free(info->dir_flags);
    if (n >= 1)
        free(info->dir);
    if (n >= 2)
        free(info->fc);
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
        if (i < 5)
            info->dir[i] = 0;
    }
    info->map = NULL;
    info->map_test = NULL;
    info->map_before = NULL;
    info->map_flag = 0;
    info->height = 0;
    info->width = 0;
    return (SUCCESS);
}