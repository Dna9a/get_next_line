/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:21:00 by yoabied           #+#    #+#             */
/*   Updated: 2026/01/01 16:21:00 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
size_t	ft_strcpy(char *dst, const char *src);
void	free_ptr(char **ptr);
char	*ft_strchr(const char *s, int c);
char	*fttitistrjoin(char *s1, const char *s2);
char	*stashsys(char *p);
char	*ineeddaline(char *delulu);
char	*get_next_line(int fd);

#endif
