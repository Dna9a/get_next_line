/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:55:37 by yoabied           #+#    #+#             */
/*   Updated: 2025/12/20 21:07:26 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h> // msa7haa ya jmiiii
# include <stdlib.h>
# include <unistd.h>

char	*ftstashsys(char *p);
char	*get_next_line(int fd);
char	*fttitistrjoin(char *s1, char const *s2);

size_t	ftitistrlen(const char *s);
// char	*ftitistrchr(const char *s, int c);

#endif
