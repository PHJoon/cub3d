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

int main(int ac, char *av[])
{
	t_info  info;
	t_var   var;
	int     fd;

	// 인자 체크
	if (check_arg(ac, av) == FAIL)
		return (EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (print_error("Open Error"));
	// 구조체 초기화 및 메모리 할당: enum 추가 사용 이외에는 추가 x
	if (init_info(&info) == FAIL)
		return (print_error("Malloc Error"));
	// 인자 파싱: 완료
	if (parse_file(fd, &info) == FAIL)
	{
		// free_info(&info, 0);
		return (print_error("Parsing Error"));
	}
	// 유효성 체크
	if (valid_info(&info) == FAIL)
	{
		// free_info(&info, 0);
		return (print_error("Validity Error"));
	}
	// 초기화
	var_init(&var, &info);
	mlx_total_init(&var);
	// mlx 시작
	// mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
	key_hook_main(&var);
	mlx_loop_hook(var.mlx, &start_mlx, &var);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}
