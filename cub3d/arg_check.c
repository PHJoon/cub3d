/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joon-lee <joon-lee@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:29:33 by joon-lee          #+#    #+#             */
/*   Updated: 2023/08/22 14:29:36 by joon-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_flag	check_arg_cnt(int ac)
{
	if (ac != 2)
		return (FAIL);
	return (SUCCESS);
}

static t_flag	check_arg_ext(char *arg)
{
	static char	*idf = ".cub";
	int			cnt;
	size_t		idx;

	cnt = 5;
	idx = ft_strlen(arg);
	while (cnt)
	{
		if (arg[idx--] != idf[cnt - 1])
			return (FAIL);
		cnt--;
	}
	return (SUCCESS);
}

t_flag	check_arg(int ac, char **av)
{
	if (check_arg_cnt(ac) == FAIL)
		return (FAIL);
	if (check_arg_ext(av[1]) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
