# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 19:03:56 by mkacemi           #+#    #+#              #
#    Updated: 2026/01/17 19:16:56 by mkacemi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       stack/basic_stack_functions.c \
       operations/operations1.c \
       operations/operations2.c \
       operations/operations3.c \
       operations/operations4.c \
       algorithms/algorithm_simple/algorithme_simple1.c \
       algorithms/algorithm_simple/utils.c \
       algorithms/algorithme_medium/algorithme_medium1.c

OBJS = $(SRCS:.c=.o)

HEADERS = main.h \
          stack/stack.h \
          operations/operations.h \
          algorithms/algorithm_simple/algorithme_simple.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compilé avec succès !"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Fichiers objets supprimés"

fclean: clean
	rm -f $(NAME)
	@echo "$(NAME) supprimé"

re: fclean all

test: $(NAME)
	./$(NAME)

git:
	git add .
	git commit -m "$(msg)"
	git push

.PHONY: all clean fclean re test git