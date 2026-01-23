# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 19:03:56 by mkacemi           #+#    #+#              #
#    Updated: 2026/01/23 16:21:10 by hhamidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main/main.c \
	   main/display_utils.c \
       stack/stack_utils1.c \
       stack/stack_utils2.c \
	   libft/ft_isdigit.c \
	   libft/ft_strlen.c \
	   libft/ft_atol.c \
	   libft/ft_strdup.c \
	   libft/ft_strjoin.c \
	   libft/ft_split.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_strcmp.c \
	   libft/ft_strcpy.c \
	   parsing/parse.c \
	   parsing/parse_utils.c \
	   parsing/parse_flags.c \
	   parsing/parse_numbers.c \
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
		  libft/libft.h \
		  parsing/parse.h \
          operations/operations.h \
          algorithms/algorithm_simple/algorithme_simple.h \
          algorithms/algorithme_medium/algorithme_medium.h \
          algorithms/algorithme_complexe/algorithme_complexe.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully !"
	./$(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Deleted object files"

fclean: clean
	rm -f $(NAME)
	@echo "$(NAME) Deleted"

re: fclean all

git:
	git add .
	git commit -m "$(msg)"
	git push

.PHONY: all clean fclean re git
