/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_parse_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:12:44 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/22 12:10:42 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void    check_map_flag(t_info *info)
{
    int i;
    int cnt;

    i = -1;
    cnt = 0;
    if (!info->map_flag)
    {
        while (++i < 6)
            cnt += info->dir_flags[i];
        if (cnt == 6)
            info->map_flag = 1;
    }
}

t_flag  parse_file(int fd, t_info *info)
{
    char    *str;

    while (1)
    {
        str = get_next_line(fd);
        if (!str)
        {
            if (!info->map_flag)
                return (FAIL);
            if (!info->map_before)
                return (FAIL);
            break ;
        }
        //map parse
        if (info->map_flag)
            parse_map(str, info);
        else
        {
            //wall texture & ceiling & floor color parse
            if (parse_info(str, info) == FAIL)
                return (free_str(str, FAIL));
        }
        check_map_flag(info);
        free(str);
    }
    return (SUCCESS);
}
