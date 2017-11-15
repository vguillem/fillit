# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:55:19 by vguillem          #+#    #+#              #
#    Updated: 2017/11/12 11:40:11 by vguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS =				main.c \
					check.c \
					create.c \
					solver.c \


INCLUDE =	fillit.h \
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
