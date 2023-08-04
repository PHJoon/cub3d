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

static t_flag parse_dir(t_info *info, char **tmp)
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
                return (FAIL);
            tmp_b = ft_strtrim(tmp[1], " ");
            info->dir[i] = ft_strtrim(tmp_b, "\n");
            free(tmp_b);
            info->dir_flags[i] = 1;
            return (SUCCESS);
        }
    }
    return (FAIL);
}

static t_flag parse_fc(t_info *info, char **tmp)
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
                return (free_split(tmp_split, FAIL));
            if (ft_sstrlen(tmp_split) != 3)
                return (free_split(tmp_split, FAIL));
            info->fc[(i * 3)] = ft_strtrim(tmp_split[0], " ");
            info->fc[(i * 3) + 1] = ft_strtrim(tmp_split[1], " ");
            tmp_b = ft_strtrim(tmp_split[2], "\n");
            info->fc[(i * 3) + 2] = ft_strtrim(tmp_b, " ");
            free(tmp_b);
            info->dir_flags[i + 4] = 1;
            return (free_split(tmp_split, SUCCESS));
        }
    }
    return (FAIL);
}

t_flag  parse_info(char *s, t_info *info)
{
    char        **tmp;

    tmp = ft_split(s, ' ');
    if (!tmp)
        return (FAIL);
    if (!ft_strncmp(tmp[0], "\n", 1)) // if there is nothing, it is an error
        return (free_split(tmp, SUCCESS));
    if (!(ft_sstrlen(tmp) == 2 || ft_sstrlen(tmp) == 4)) // the num of chunk has to be 2 or 4
        return (free_split(tmp, FAIL));
    if (parse_dir(info, tmp) == SUCCESS)
        return (free_split(tmp, SUCCESS));
    if (parse_fc(info, tmp) == SUCCESS)
        return (free_split(tmp, SUCCESS));
    return (free_split(tmp, FAIL));
}

t_flag parse_map(char *s, t_info *info)
{
    char    *tmp;

    tmp = ft_strtrim(s, " ");
    if (!ft_strncmp(tmp, "\n", 2))
        return (free_str(tmp, FAIL));
    free(tmp);
    if (info->map_before)
    {
        tmp = ft_strdup(info->map_before);
        free(info->map_before);
        info->map_before = ft_strjoin(tmp, s);
    }
    else
        info->map_before = ft_strdup(s);
    return (SUCCESS);
}
