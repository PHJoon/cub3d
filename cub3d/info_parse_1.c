/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_parse_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:12:44 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/27 15:59:45 by hyungjpa         ###   ########.fr       */
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

int parse_file(int fd, t_info *info)
{
    char *s;

    while (1)
    {
        s = get_next_line(fd);
        if (!s)
        {
            if (!info->map_flag)
                return (0);
            break ;
        }
        if (info->map_flag)
            parse_map(s, info);
        else
        {
            if (!parse_info(s, info))
                return (free_str(s, 0));
        }
        check_map_flag(info);
        free(s);
    }
    return (1);
}
