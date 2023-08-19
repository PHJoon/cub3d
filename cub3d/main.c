/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:22:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/08 16:22:49 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void aaa(void)
{
	system("leaks cub3D | grep leaked");
}


int main(int ac, char *av[])
{
	atexit(aaa);
	t_info  info;
	t_var   var;
	int     fd;

	// 인자 체크: leak 문제 없음
	if (check_arg(ac, av) == FAIL)
		return (print_error("Error"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (print_error("Error"));
	// 구조체 초기화 및 메모리 할당: leak 문제 없음
	init_info(&info);
	// 인자 파싱: leak 문제 없음
	if (parse_file(fd, &info) == FAIL)
	{
		free_info(&info, 0);
		return (print_error("Error"));
	}
	// 유효성 체크: leak 문제 없음
	if (valid_info(&info) == FAIL)
	{
		free_info(&info, 0);
		return (print_error("Error"));
	}
	// 초기화
	var_init(&var, &info);
	mlx_total_init(&var);
	// mlx 시작
	key_hook_main(&var);
	mlx_loop_hook(var.mlx, &start_mlx, &var);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}
