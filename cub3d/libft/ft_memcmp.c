/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:08:25 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/10 15:40:03 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*r_s1;
	const unsigned char	*r_s2;
	size_t				i;

	r_s1 = s1;
	r_s2 = s2;
	i = 0;
	while (i != n)
	{
		if (r_s1[i] != r_s2[i])
			return ((int)(r_s1[i] - r_s2[i]));
		i++;
	}
	return (0);
}
