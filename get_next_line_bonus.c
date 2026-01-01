/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:21:00 by yoabied           #+#    #+#             */
/*   Updated: 2026/01/01 16:21:00 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_read(int fd, char *stash)
{
	int		byte_readed;
	char	*buf_read;

	buf_read = malloc(BUFFER_SIZE + 1);
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
		return (NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*alr_read;
	static char	*stash[MAX_FD];

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	alr_read = gnl_read(fd, stash[fd]);
	if (!alr_read)
	{
		free_ptr(&stash[fd]);
		return (NULL);
	}
	stash[fd] = alr_read;
	line = ineeddaline(stash[fd]);
	stash[fd] = stashsys(stash[fd]);
	if (line == NULL)
	{
		free_ptr(&stash[fd]);
	}
	return (line);
}
