/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:24 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/24 14:29:48 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	free_str(char *s, int res)
{
	free(s);
	return (res);
}

char	**free_split_fail(char **s, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(s[i]);
	free(s);
	return (NULL);
}

int	free_split(char **s, int res)
{
	int	i;

	i = -1;
	while (++i < ft_sstrlen(s))
		free(s[i]);
	free(s);
	return (res);
}

int	free_map(char **s, int res, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(s[i]);
	free(s);
	return (res);
}

int	free_info(t_info *info, int res)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		free(info->fc[i]);
		if (i < 4)
			free(info->dir[i]);
	}
	free(info->fc);
	free(info->dir);
	free(info->dir_flags);
	free(info->fc_num);
	free(info->text_arr);
	if (info->map_before)
		free(info->map_before);
	if (info->map)
		free_map(info->map, 1, info->height);
	if (info->map_test)
		free_map(info->map_test, 1, info->height);
	return (res);
}
