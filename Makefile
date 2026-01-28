# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 19:03:56 by mkacemi           #+#    #+#              #
#    Updated: 2026/01/28 17:23:10 by hhamidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft

COMMON_SRCS = stack/stack_utils1.c \
			  stack/stack_utils2.c \

SRCS = main/main.c \
	   main/display_utils.c \
	   main/display_utils2.c \
	   parsing/parse.c \
	   parsing/parse_utils.c \
	   parsing/parse_flags.c \
	   parsing/parse_numbers.c \
	   operations/operations1.c \
	   operations/operations2.c \
	   operations/operations3.c \
	   operations/operations4.c \
       algorithms/adaptive/adaptive.c \
       algorithms/algorithm_simple/algorithme_simple1.c \
       algorithms/algorithm_simple/utils.c \
       algorithms/algorithme_medium/algorithme_medium1.c \
       algorithms/algorithme_medium/utils1.c \
       algorithms/algorithme_medium/utils2.c \
       algorithms/algorithme_complexe/algorithme_complexe.c \
	   $(COMMON_SRCS)

BONUS_SRCS = bonus/checker.c \
			bonus/checker_utils.c \
			bonus/read.c \
			bonus/parsing/parse.c \
			bonus/parsing/parse_utils.c \
			bonus/parsing/parse_numbers.c \
			bonus/operations_bonus/swap.c \
			bonus/operations_bonus/push.c \
			bonus/operations_bonus/rotate.c \
			bonus/operations_bonus/reverse_rotate.c \
			$(COMMON_SRCS)

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADERS = main/main.h \
          stack/stack.h \
		  parsing/parse.h \
          operations/operations.h \
          algorithms/algorithm_simple/algorithme_simple.h \
          algorithms/algorithme_medium/algorithme_medium.h \
          algorithms/algorithme_complexe/algorithme_complexe.h

BONUS_HEADERS = bonus/checker.h \
				bonus/parsing/parse.h \
				bonus/operations_bonus/operations.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) compiled successfully !"

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(BONUS_NAME) compiled successfully !"

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(BONUS_HEADERS) $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C libft clean
	@echo "Object files deleted"

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C libft fclean
	@echo "Executables Deleted"

re: fclean all

.PHONY: all clean fclean re bonus
