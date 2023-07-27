/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:04:06 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/17 13:27:12 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_int_char(int n, int fd)
{
	char	x;

	x = (n % 10) + 48;
	if (n >= 10)
	{
		ft_int_char(n / 10, fd);
		ft_int_char(n % 10, fd);
	}
	else
		write(fd, &x, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_int_char(-n, fd);
	}
	else
		ft_int_char(n, fd);
}
