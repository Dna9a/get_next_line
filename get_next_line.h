/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:55:37 by yoabied           #+#    #+#             */
/*   Updated: 2025/12/26 21:23:36 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
size_t	ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*fttitistrjoin(char *s1, const char *s2);
char	*stashsys(char *p);
char	*ineeddaline(char *delulu);
char	*get_next_line(int fd);

#endif
