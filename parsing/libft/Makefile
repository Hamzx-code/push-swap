# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 15:28:58 by hhamidi           #+#    #+#              #
#    Updated: 2026/01/22 14:27:44 by hhamidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
SRCS = ft_isdigit.c \
	   ft_strlen.c \
	   ft_atol.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_split.c \
	   ft_putstr_fd.c \
	   ft_strcmp.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
NAME = libft.a

all: $(NAME) 

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
