/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:47:03 by yoabied           #+#    #+#             */
/*   Updated: 2025/12/30 20:12:51 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (byte_readed < 0)
			break ;
		if (byte_readed == 0)
			break ;
		buf_read[byte_readed] = '\0';
		stash = fttitistrjoin(stash, buf_read);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buf_read);
	if (byte_readed < 0)
		return (NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*alr_read;
	static char	*stash;

	alr_read = gnl_read(fd, stash);
	if (!alr_read)
		return (NULL);
	stash = alr_read;
	line = ineeddaline(stash);
	stash = stashsys(stash);
	return (line);
}
