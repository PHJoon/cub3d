/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/27 16:05:14 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ft_sstrlen(char **tmp)
{
    int i;

    i = 0;
    while (tmp[i])
        i++;
    return (i);
}

t_flag print_error(char *msg)
{
    ft_putendl_fd(msg, STDERR_FILENO);
    return (FAIL);
}

void    display(t_info *info)
{
    printf("dir: %s, %s, %s, %s\n", info->dir[0], info->dir[1], info->dir[2], info->dir[3]);
    printf("fc : %s, %s, %s, %s, %s, %s\n", info->fc[0], info->fc[1], info->fc[2], info->fc[3], info->fc[4], info->fc[5]);
    printf("map_before : %s\n", info->map_before);

    int t = -1;
    int k;
    // printf("map_test : \n");
    // while (++t < info->height)
    // {
    //     k = -1;
    //     while (++k < info->width)
    //         printf("%c", info->map_test[t][k]);
    //     printf("\n");
    // }

    printf("map : \n");
    while (++t < info->height)
    {
        k = -1;
        while (++k < info->width)
            printf("%c", info->map[t][k]);
        printf("\n");
    }
    
}