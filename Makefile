# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 16:21:00 by yoabied           #+#    #+#              #
#    Updated: 2026/01/01 16:21:00 by yoabied          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
BONUS_NAME = get_next_line_bonus.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 42

SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	ar rcs $(BONUS_NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
