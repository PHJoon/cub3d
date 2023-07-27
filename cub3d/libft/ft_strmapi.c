/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:24:34 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/10 21:43:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	s_len;
	unsigned int	i;
	char			*arr;

	i = 0;
	s_len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!arr)
		return (0);
	while (s[i])
	{
		arr[i] = f(i, (char)s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
