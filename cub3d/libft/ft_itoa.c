/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:55:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/10 22:24:41 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*do_itoa(char *arr, int n, int size)
{
	int	minus;

	minus = 1;
	if (n < 0)
	{
		arr[0] = '-';
		minus = -1;
	}
	arr[size] = '\0';
	size--;
	if (n == 0)
	{
		arr[size] = 48;
		return (arr);
	}
	while (n != 0)
	{
		arr[size] = (minus * (n % 10)) + 48;
		n /= 10;
		size--;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;

	size = get_size(n);
	if (n <= 0)
		size++;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	arr = do_itoa(arr, n, size);
	return (arr);
}
