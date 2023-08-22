/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_valid_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:18:15 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/22 14:01:40 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	**make_map_malloc(t_info *info, char **tmp)
{
	int		i;
	char	**map;

	i = -1;
	info->height = ft_sstrlen(tmp);
	while (++i < info->height)
	{
		if (info->width < (int)ft_strlen(tmp[i]))
			info->width = (int)ft_strlen(tmp[i]);
	}
	map = (char **)malloc(sizeof(char *) * info->height);
	if (!map)
		return (NULL);
	i = -1;
	while (++i < info->height)
	{
		map[i] = (char *)malloc(sizeof(char) * info->width);
		if (!map[i])
			return (free_split_fail(map, i));
		ft_memset(map[i], ' ', info->width);
	}
	return (map);
}

static char	**make_map(t_info *info)
{
	int		i;
	int		j;
	char	**tmp;
	char	**map;

	i = -1;
	tmp = ft_split(info->map_before, '\n');
	map = make_map_malloc(info, tmp);
	if (!map)
	{
		free_split(tmp, 0);
		return (0);
	}
	while (++i < info->height)
	{
		j = -1;
		while (++j < (int)ft_strlen(tmp[i]))
			map[i][j] = tmp[i][j];
	}
	free_split(tmp, 1);
	return (map);
}

t_flag	valid_info(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 6)
	{
		j = -1;
		while (++j < (int)ft_strlen(info->fc[i]))
		{
			if (!ft_isdigit(info->fc[i][j]))
				return (FAIL);
		}
		info->fc_num[i] = ft_atoi(info->fc[i]);
		if (info->fc_num[i] < 0 || info->fc_num[i] > 255)
			return (FAIL);
	}
	info->map = make_map(info);
	info->map_test = make_map(info);
	if (check_map_args(info) == FAIL)
		return (FAIL);
	if (check_map_cross(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
