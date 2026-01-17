# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 19:03:56 by mkacemi           #+#    #+#              #
#    Updated: 2026/01/16 19:09:41 by mkacemi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc

# Fichiers sources
SRCS = main.c \
       stack/basic_stack_functions.c \
       operations/operations1.c \
       operations/operations2.c \
       operations/operations3.c \
       algorithms/algorithm_simple/algorithme_simple1.c \
       algorithms/algorithm_simple/utils.c \
       algorithms/algorithme_medium/algorithme_medium1.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Headers
HEADERS = main.h \
          stack/stack.h \
          operations/operations.h \
          algorithms/algorithm_simple/algorithme_simple.h

# Règle par défaut
all: $(NAME)

# Compilation du programme
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "✅ $(NAME) compilé avec succès !"

# Compilation des fichiers .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)
	@echo "🧹 Fichiers objets supprimés"

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	@echo "🗑️  $(NAME) supprimé"

# Recompilation complète
re: fclean all

# Exécution avec des arguments de test
test: $(NAME)
	./a.out

git:
	git add .
	git commit -m "$(msg)"
	git push
# Phony targets
.PHONY: all clean fclean re test