/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:47:03 by yoabied           #+#    #+#             */
/*   Updated: 2025/12/23 12:29:22 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	int			byte_readed;
	char		*line;
	char		*buf_read;
	static char	*stash;

	buf_read = malloc(BUFFER_SIZE + 1);
	if (!buf_read)
		return (NULL);
	byte_readed = 1;
	while (byte_readed != 0)
	{
		byte_readed = read(fd, buf_read, BUFFER_SIZE);
		if (byte_readed < 0)
		{
			free(buf_read);
			return (NULL);
		}
		if (byte_readed == 0)
			break ;
		buf_read[byte_readed] = '\0';
		stash = fttitistrjoin(stash, buf_read);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buf_read);
	if (!stash)
		return (NULL);
	line = ineeddaline(stash);
	stash = stashsys(stash);
	return (line);
}
