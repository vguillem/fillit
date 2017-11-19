# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:55:19 by vguillem          #+#    #+#              #
#    Updated: 2017/11/19 12:15:32 by vguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS =				rendu/main.c \
					rendu/check.c \
					rendu/create.c \
					rendu/solver.c \
					rendu/map.c \
					rendu/print.c \
					rendu/free.c \


INCLUDE =	rendu/fillit.h \
			libft/libft.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(FLAGS) $(OBJS) -L libft/ -lft -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $? -c -o $@

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
	make -C libft/ re
