/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:57:02 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/21 13:54:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	gnl_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*do_strjoin(char *s1, char *s2, char *ptr)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	j = 0;
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	while (i < s1_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*gnl_strjoin(char **s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	s1_len = gnl_strlen(*s1);
	s2_len = gnl_strlen(s2);
	if (s1_len == 0 && s2_len == 0)
		return (do_free(s1));
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (do_free(s1));
	ptr = do_strjoin(*s1, s2, ptr);
	free(*s1);
	*s1 = NULL;
	return (ptr);
}
