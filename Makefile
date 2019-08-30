# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solivari <solivari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 09:58:50 by solivari          #+#    #+#              #
#    Updated: 2019/08/30 20:37:48 by solivari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRCS1 = Operations_1.c Operations_2.c checksort.c errorcheck.c fucklinklists.c push_swap.c\
		qsort.c extra_functions.c errors.c group.c algofuncs.c libft/libft.a

SRCS2 = Operations_1.c Operations_2.c checksort.c errorcheck.c fucklinklists.c checker.c\
		extra_functions.c errors.c libft/libft.a

FLAGS = -Wall -Wextra -Werror

HEAD = push_swap.h

all: $(NAME1) $(NAME2)

again: $(NAME2)
	gcc $(FLAGS) $(SRCS1) -o $(NAME1)

$(NAME1):
	make -C ./libft re
	gcc $(FLAGS) $(SRCS1) -o $(NAME1)

$(NAME2):
	gcc $(FLAGS) $(SRCS2) -o $(NAME2)

clean:
	/bin/rm -f $(NAME1) $(NAME2)

re: clean again
