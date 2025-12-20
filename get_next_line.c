/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:47:03 by yoabied           #+#    #+#             */
/*   Updated: 2025/12/20 21:08:42 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
size_t	c_lengh(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

char	*fttitistrjoin(char *s1, const char *s2)
{
	char	*r;
	size_t	i;

	// s2 uhmmm za3ma ? idk if its naicessary
	if (!s1)
	{
		s1 = calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	r = (char *)malloc(ftitistrlen(s1) + ftitistrlen(s2) + 1);
	if (!r)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	i = ft_mystcpy(r, s1);
	i += ft_mystcpy(r + i, s2);
	r[i] = '\0';
	free(s1);
	return (r);
}

char	*stashsys(char *p)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	while (p[i] && p[i] != '\n')
		i++;
	if (!p[i])
	{
		free(p);
		return (NULL);
	}
	new_stash = malloc(ftitistrlen(p) - i + 1);
	if (!new_stash) // wouach nrefreeyi or idk
		return (NULL);
	i++;
	j = 0;
	while (p[i])
		new_stash[j++] = p[i++];
	new_stash[j] = '\0';
	free(p);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf_read;
	int			byte_readed;

	byte_readed = 1;
	while (byte_readed != 0)
	{
		byte_readed = read(fd, buf_read, BUFFER_SIZE);
	}
}

// IneedDanline(char *incdex)
// {
// 	size_t	i;

// 	i = 0;
// 	while (incdex[i] != '\n' || incdex[i] != '\0')
// 	{
// 		incdex[i++];
// 	}
// }

// loop search for new line or end of line
// stop loop:
// (check if the read function return 0
// check if stash hold new line