/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_parse_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:29:04 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/27 16:00:15 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int parse_dir(t_info *info, char **tmp)
{
    int         i;
    char        *tmp_b;
    const char  *dir_list[4] = {"NO", "SO", "WE", "EA"};
    
    i = -1;
    while (++i < 4)
    {
        if (!ft_strncmp(tmp[0], dir_list[i], 3))
        {
            if (info->dir_flags[i])
                return (0);
            tmp_b = ft_strtrim(tmp[1], " ");
            info->dir[i] = ft_strtrim(tmp_b, "\n");
            free(tmp_b);
            info->dir_flags[i] = 1;
            return (1);
        }
    }
    return (0);
}

static int parse_fc(t_info *info, char **tmp)
{
    int     i;
    char    *tmp_b;
    char    **tmp_split;
    const char  *fc_list[2] = {"F", "C"};

    i = -1;
    while (++i < 2)
    {
        if (!ft_strncmp(tmp[0], fc_list[i], 2))
        {
            tmp_split = ft_split(tmp[1], ',');
            if (info->dir_flags[i + 4])
                return (free_split(tmp_split, 0));
            if (ft_sstrlen(tmp_split) != 3)
                return (free_split(tmp_split, 0));
            info->fc[(i * 3)] = ft_strtrim(tmp_split[0], " ");
            info->fc[(i * 3) + 1] = ft_strtrim(tmp_split[1], " ");
            tmp_b = ft_strtrim(tmp_split[2], "\n");
            info->fc[(i * 3) + 2] = ft_strtrim(tmp_b, " ");
            free(tmp_b);
            info->dir_flags[i + 4] = 1;
            return (free_split(tmp_split, 1));
        }
    }
    return (0);
}

int parse_info(char *s, t_info *info)
{
    char        **tmp;

    tmp = ft_split(s, ' ');
    if (!ft_strncmp(tmp[0], "\n", 1))
        return (free_split(tmp, 1));
    if (!(ft_sstrlen(tmp) == 2 || ft_sstrlen(tmp) == 4))
        return (free_split(tmp, 0));
    if (parse_dir(info, tmp))
        return (free_split(tmp, 1));
    if (parse_fc(info, tmp))
        return (free_split(tmp, 1));
    return (free_split(tmp, 0));
}

int parse_map(char *s, t_info *info)
{
    char    *tmp;

    tmp = ft_strtrim(s, " ");
    if (!ft_strncmp(tmp, "\n", 2))
        return (free_str(tmp, 1));
    free(tmp);
    if (info->map_before)
    {
        tmp = ft_strdup(info->map_before);
        free(info->map_before);
        info->map_before = ft_strjoin(tmp, s);
    }
    else
        info->map_before = ft_strdup(s);
    return (1);
}
