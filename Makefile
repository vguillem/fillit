# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:55:19 by vguillem          #+#    #+#              #
#    Updated: 2017/11/18 18:20:56 by vguillem         ###   ########.fr        #
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
	$(CC) $(FLAGS) $(OBJS) -L libft/ -lft -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $? -c -o $@

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
