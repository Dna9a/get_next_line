/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:40:27 by yoabied           #+#    #+#             */
/*   Updated: 2026/01/01 16:17:20 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

size_t	ft_strlen(const char *s)
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

char	*fttitistrjoin(char *s1, const char *s2)
{
	size_t	i;
	char	*r;

	i = 0;
	if (!s1)
	{
		s1 = calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	r = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r)
	{
		free_ptr(&s1);
		return (NULL);
	}
	i = ft_strcpy(r, s1);
	i += ft_strcpy(r + i, s2);
	r[i] = '\0';
	free_ptr(&s1);
	return (r);
}

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
