/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/22 15:34:16 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_sstrlen(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

t_flag	print_error_n_free(char *msg, t_info *info)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (info)
		free_info(info, 0);
	return (FAIL);
}

t_flag	flag_check(int flag)
{
	if (flag != 2)
		return (FAIL);
	return (SUCCESS);
}
