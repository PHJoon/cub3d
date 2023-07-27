/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:47:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/10 19:13:31 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static unsigned int	get_s_e(char const *s1, char const *set, unsigned int k)
{
	if (k == 0)
	{
		k = 0;
		while (s1[k])
		{
			if (check_set(s1[k], set))
				k++;
			else
				break ;
		}
		return (k);
	}
	k = ft_strlen(s1) - 1;
	while (k >= 0)
	{
		if (check_set(s1[k], set))
			k--;
		else
			break ;
	}
	return (k);
}

static char	*do_strtrim(char const *s1, unsigned int a, unsigned int b)
{
	unsigned int	m;
	char			*ptr;

	m = 0;
	if (a == 0 && b == 0)
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		if (!ptr)
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (b - a + 2));
	if (!ptr)
		return (0);
	while (a < b + 1)
	{
		ptr[m] = s1[a];
		a++;
		m++;
	}
	ptr[m] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = get_s_e(s1, set, 0);
	if (i == ft_strlen(s1))
		j = i;
	else
		j = get_s_e(s1, set, 1);
	return (do_strtrim(s1, i, j));
}
