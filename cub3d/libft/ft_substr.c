/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:25:44 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/10 17:39:37 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char) * 1);
		if (!sub)
			return (0);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(s) < len + start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (len-- != 0 && start < ft_strlen(s))
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
