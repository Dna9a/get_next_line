/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younux <younux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:47:03 by yoabied           #+#    #+#             */
/*   Updated: 2026/01/02 01:46:26 by younux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ineeddaline(char *delulu)
{
	size_t	i;
	size_t	j;
	char	*new_el;

	if (!delulu)
		return (NULL);
	i = 0;
	while (delulu[i] && delulu[i] != '\n')
		i++;
	new_el = malloc(i + (delulu[i] == '\n') + 1);
	if (!new_el)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_el[j] = delulu[j];
		j++;
	}
	if (delulu[i] == '\n')
		new_el[j++] = '\n';
	new_el[j] = '\0';
	return (new_el);
}

char	*stashsys(char *p)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	while (p[i] && p[i] != '\n')
		i++;
	if (!p[i] || p[i + 1] == '\0')
	{
		free_ptr(&p);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(p) - i + 1);
	if (!new_stash)
	{
		free_ptr(&p);
		return (NULL);
	}
	i++;
	j = 0;
	while (p[i])
		new_stash[j++] = p[i++];
	new_stash[j] = '\0';
	free_ptr(&p);
	return (new_stash);
}

char	*cutof_gnl_read(char *stash)
{
	char	*buf_read;

	buf_read = malloc(BUFFER_SIZE + 1);
	if (!buf_read)
	{
		free_ptr(&stash);
		return (NULL);
	}
	return (buf_read);
}

char	*gnl_read(int fd, char *stash)
{
	int		byte_readed;
	char	*buf_read;

	buf_read = cutof_gnl_read(stash);
	if (!buf_read)
		return (NULL);
	byte_readed = 1;
	while (byte_readed != 0)
	{
		byte_readed = read(fd, buf_read, BUFFER_SIZE);
		if (byte_readed <= 0)
			break ;
		buf_read[byte_readed] = '\0';
		stash = fttitistrjoin(stash, buf_read);
		if (stash == NULL || ft_strchr(stash, '\n'))
			break ;
	}
	free_ptr(&buf_read);
	if (byte_readed < 0)
	{
		free_ptr(&stash);
		return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	stash = gnl_read(fd, stash);
	if (!stash)
	{
		return (NULL);
	}
	line = ineeddaline(stash);
	stash = stashsys(stash);
	if (line == NULL)
	{
		free_ptr(&stash);
	}
	return (line);
}
