/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:40:27 by yoabied           #+#    #+#             */
/*   Updated: 2026/01/02 16:01:34 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
