# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 19:03:56 by mkacemi           #+#    #+#              #
#    Updated: 2026/01/22 01:57:37 by mkacemi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main/main.c \
	   main/display_utils.c \
       stack/stack_utils1.c \
       stack/stack_utils2.c \
       operations/operations1.c \
       operations/operations2.c \
       operations/operations3.c \
       operations/operations4.c \
       algorithms/algorithm_simple/algorithme_simple1.c \
       algorithms/adaptive/adaptive.c \
       algorithms/algorithm_simple/utils.c \
       algorithms/algorithme_medium/algorithme_medium1.c \
       algorithms/algorithme_medium/utils1.c \
       algorithms/algorithme_medium/utils2.c \
       algorithms/algorithme_complexe/algorithme_complexe.c

OBJS = $(SRCS:.c=.o)

HEADERS = main/main.h \
          stack/stack.h \
          operations/operations.h \
          algorithms/algorithm_simple/algorithme_simple.h \
          algorithms/algorithme_medium/algorithme_medium.h \
          algorithms/algorithme_complexe/algorithme_complexe.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compilé avec succès !"
	./$(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Fichiers objets supprimés"

fclean: clean
	rm -f $(NAME)
	@echo "$(NAME) supprimé"

re: fclean all

git:
	git add .
	git commit -m "$(msg)"
	git push

.PHONY: all clean fclean re git