/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:22:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/27 16:00:17 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char *av[])
{
	t_info	info;
	t_var	var;
	int		fd;

	if (check_arg(ac, av) == FAIL)
		print_error_n_free("Argument Error", 0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error_n_free("Open Error", 0);
	init_info(&info);
	if (parse_file(fd, &info) == FAIL)
		print_error_n_free("Parsing Error", &info);
	if (valid_info(&info) == FAIL)
		print_error_n_free("Validation Error", &info);
	var_init(&var, &info);
	if (mlx_total_init(&var) == FAIL)
		print_error_n_free("Mlx Error", &info);
	key_hook_main(&var);
	mlx_loop_hook(var.mlx, &start_mlx, &var);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}
