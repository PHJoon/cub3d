/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:41:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/09 21:14:26 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0 && n > 0)
		return (dst);
	while (i != n)
	{
		*(unsigned char *)(dst + i) = *(const unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
