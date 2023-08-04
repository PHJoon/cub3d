/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_valid_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:12:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/04 16:55:27 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int check_args(char c, int *flag, int i, int j)
{
    int     k;
    const char *player = "NSWE";

    k = -1;
    if (!(c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == ' '))
        return (0);
    while (++k < 4 && c == player[k])
    {
        if (c == player[k])
        {
            if (*flag)
                return (0);
            *flag = 1;
        }
    }
    return (1);
}

int check_map_args(t_info *info)
{
    int i;
    int j;
    int flag;

    flag = 0;
    i = -1;
    while (++i < info->height)
    {
        j = -1;
        while (++j < info->width)
        {
            if (!check_args(info->map_test[i][j], &flag, i, j))
                return (0);
            if (flag == 1)
            {
                info->player_x = i;
                info->player_y = j;
                return (1);
            }
        }
    }
    return (0);
}

static int check_line(char c, int *cnt, int *k, int d)
{
    if (c == '1')
    {
        (*cnt)++;
        *k = d;
        return (1);
    }
    return (0);
}

static void    check_cross(t_info *info, int i, int j, int *cnt)
{
    int k;

    k = i;
    while (--k > -1 && info->map_test[k][j] != ' ')
    {
        if (check_line(info->map_test[k][j], cnt, &k, i))
            break ;
    }
    while (++k < info->height && info->map_test[k][j] != ' ')
    {
        if (check_line(info->map_test[k][j], cnt, &k, j))
            break ;
    }
    while (--k > -1 && info->map_test[i][k] != ' ')
    {
        if (check_line(info->map_test[i][k], cnt, &k, j))
            break ;
    }
    while (++k < info->width && info->map_test[i][k] != ' ')
    {
        if (check_line(info->map_test[i][k], cnt, &k, j))
            break ;
    }
}

int check_map_cross(t_info *info)
{
    int i;
    int j;
    int cnt;

    i = -1;
    while (++i < info->height)
    {
        j = -1;
        while (++j < info->width)
        {
            if (info->map_test[i][j] == '0')
            {
                cnt = 0;
                check_cross(info, i, j, &cnt);
                if (cnt != 4)
                    return (0);
                else
                    info->map_test[i][j] = '1';
            }
        }
    }
    return (1);
}
