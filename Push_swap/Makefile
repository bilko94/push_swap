# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solivari <solivari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 09:58:50 by solivari          #+#    #+#              #
#    Updated: 2019/09/03 10:33:04 by solivari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME1 = checker

SRCS = operations_1.c operations_2.c checksort.c errorcheck.c creator.c push_swap.c\
		qsort.c extra_functions.c errors.c group.c algofuncs.c shortsort.c operations_3.c\
		qsorta.c libft/libft.a

SRCS1 = operations_1.c operations_2.c checksort.c errorcheck.c creator.c checker.c\
		extra_functions.c errors.c visualizer.c operations_3.c libft/libft.a

FLAGS = -Wall -Wextra -Werror

HEAD = push_swap.h

all: $(NAME) $(NAME1)

again: $(NAME1)
	gcc $(FLAGS) $(SRCS) -o $(NAME)

$(NAME):
	make -C ./libft re
	gcc $(FLAGS) $(SRCS) -o $(NAME)

$(NAME1):
	gcc $(FLAGS) $(SRCS1) -o $(NAME1)

clean:
	/bin/rm -f $(NAME) $(NAME1)

re: clean again
