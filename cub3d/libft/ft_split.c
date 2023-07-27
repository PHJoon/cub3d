/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:14:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/18 22:18:32 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncpy(char const *s, char *dst, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

static unsigned int	cnt_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			cnt++;
			i += j;
		}
	}
	return (cnt);
}

static void	free_all(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**do_split(char const *s, char c, char **arr)
{
	unsigned int	i;
	unsigned int	w_len;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			w_len = 0;
			while (s[i + w_len] != c && s[i + w_len])
				w_len++;
			arr[k] = (char *)malloc(sizeof(char) * (w_len + 1));
			if (!arr[k])
				return (0);
			ft_strncpy(&s[i], arr[k++], w_len);
			i += w_len;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	cnt;

	cnt = cnt_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!arr)
		return (0);
	if (do_split(s, c, arr) == 0)
	{
		free_all(arr);
		return (0);
	}
	arr[cnt] = 0;
	return (arr);
}
