/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:22:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/27 12:18:19 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int ac, char *av[])
{
    t_info  info;
    int     fd;

    if (ac != 2)
        return (0);
    // 확장자 체크
    if (ft_strncmp(ft_strchr(av[1], '.'), ".cub", 4))
        return (print_error());
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (print_error());

    // 메모리 할당
    if (!init_info(&info))
        return (print_error());

    // 인자 파싱
    if (!parse_file(fd, &info))
        return (print_error());

    // 유효성 체크
    if (!valid_info(&info))
        return (print_error());

    // mlx_init

    return (free_info(&info, 1));
}