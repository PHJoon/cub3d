/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:55:48 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/21 13:55:06 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*do_free(char **s)
{
	free(*s);
	*s = NULL;
	return (0);
}

static char	*do_read(char *backup, char *buf, int fd)
{
	ssize_t	r_bytes;

	r_bytes = 0;
	while (r_bytes >= 0)
	{
		if (gnl_strchr(backup, '\n'))
			return (backup);
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes == -1)
			return (do_free(&backup));
		if (r_bytes == 0)
			return (backup);
		buf[r_bytes] = '\0';
		backup = gnl_strjoin(&backup, buf);
		if (backup == 0)
			return (0);
	}
	return (0);
}

static char	*get_backup(char **backup, size_t i)
{
	char	*new_backup;
	size_t	b_len;
	size_t	j;

	b_len = gnl_strlen(*backup);
	j = 0;
	new_backup = (char *)malloc(sizeof(char) * (b_len - i));
	if (!new_backup)
		return (do_free(backup));
	i++;
	while (i < b_len)
	{
		new_backup[j] = (*backup)[i];
		j++;
		i++;
	}
	new_backup[j] = '\0';
	free(*backup);
	return (new_backup);
}

static char	*get_result(char **backup)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*backup)[i] != '\n' && (*backup)[i])
		i++;
	if (gnl_strlen(*backup) == i)
		i--;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (do_free(backup));
	while (j < i + 1)
	{
		result[j] = (*backup)[j];
		j++;
	}
	result[j] = '\0';
	*backup = get_backup(backup, i);
	if (*backup == 0)
		return (do_free(&result));
	return (result);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*backup;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (do_free(&backup));
	backup = do_read(backup, buf, fd);
	free(buf);
	buf = NULL;
	if (backup == 0 || gnl_strlen(backup) == 0)
		return (do_free(&backup));
	result = get_result(&backup);
	if (result == 0 || backup == 0)
	{
		free(result);
		result = NULL;
		return (do_free(&backup));
	}
	return (result);
}
