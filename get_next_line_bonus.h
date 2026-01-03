/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younux <younux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:55:37 by yoabied           #+#    #+#             */
/*   Updated: 2026/01/03 05:14:28 by younux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_BONUS
# define GET_NEXT_LINE_H_BONUS

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 10240
# endif

# include <stdlib.h>
# include <unistd.h>

void    free_ptr(char **ptr);
size_t    ft_strlen(const char *s);
size_t    ft_strcpy(char *dst, const char *src);
char    *ft_strchr(const char *s, int c);
char    *fttitistrjoin(char *s1, const char *s2);
char    *stashsys(char *p);
char    *ineeddaline(char *delulu);
char    *get_next_line(int fd);
char    *gnl_read(int fd, char *stash);
char    *cutof_gnl_read(char *stash);

#endif