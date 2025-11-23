/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:40:27 by yoabied           #+#    #+#             */
/*   Updated: 2025/11/23 21:57:59 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ftitistrchr(const char *s, int c)
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
size_t	ftitistrlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*fttitistrjoin(char const *s1, char const *s2)
{
	char *r;
	size_t l1;
	size_t l2;
	size_t i;

	if (!s1)
		return (NULL);
	l1 = ftitistrlen(s1);
	l2 = ftitistrlen(s2);
	r = (char *)malloc(l1 + l2 + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		r[i] = s1[i];
		i++;
	}
	while (i < l1 + l2)
	{
		r[i] = s2[i - l1];
		i++;
	}
	r[i] = '\0';
	return (r);
}