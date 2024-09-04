# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:03:30 by jvivas-g          #+#    #+#              #
#    Updated: 2024/09/04 18:45:25 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Colores
COLOR_RESET = "\033[0m"
COLOR_VERDE = "\033[32m"

# Lista de archivos fuente y objetos
SOURCES = src/main.c \
          src/algorithm/order.c \
          src/algorithm/aux_sort_methods.c \
          src/algorithm/sort_methods.c \
          src/algorithm/sort_methods_2.c \
          src/free/frees.c \
          src/lists/aux_lists.c \
          src/lists/aux_lists_2.c \
          src/movements/push.c \
          src/movements/reverse_rotate.c \
          src/movements/rotate.c \
          src/movements/swap.c \
          src/parse/aux_atoi.c \
          src/parse/aux_strcpy_int.c \
          src/parse/init.c \
          src/parse/parse.c \
          src/pruebas/pruebas.c

OBJECTS = src/main.o \
          src/algorithm/order.o \
          src/algorithm/aux_sort_methods.o \
          src/algorithm/sort_methods.o \
          src/algorithm/sort_methods_2.o \
          src/free/frees.o \
          src/lists/aux_lists.o \
          src/lists/aux_lists_2.o \
          src/movements/push.o \
          src/movements/reverse_rotate.o \
          src/movements/rotate.o \
          src/movements/swap.o \
          src/parse/aux_atoi.o \
          src/parse/aux_strcpy_int.o \
          src/parse/init.o \
          src/parse/parse.o \
          src/pruebas/pruebas.o

# Librería
LIBFT = lib/libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Regla principal
$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) -L lib -lft -o $(NAME)
	@echo $(COLOR_VERDE) "Created $(NAME)" $(COLOR_RESET)

# Reglas de compilación para cada archivo objeto
src/main.o: src/main.c
	@echo "Compiling main.c"
	@$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/algorithm/order.o: src/algorithm/order.c
	@echo "Compiling order.c"
	@$(CC) $(CFLAGS) -c src/algorithm/order.c -o src/algorithm/order.o

src/algorithm/aux_sort_methods.o: src/algorithm/aux_sort_methods.c
	@echo "Compiling aux_sort_methods.c"
	@$(CC) $(CFLAGS) -c src/algorithm/aux_sort_methods.c -o src/algorithm/aux_sort_methods.o

src/algorithm/sort_methods.o: src/algorithm/sort_methods.c
	@echo "Compiling sort_methods.c"
	@$(CC) $(CFLAGS) -c src/algorithm/sort_methods.c -o src/algorithm/sort_methods.o

src/algorithm/sort_methods_2.o: src/algorithm/sort_methods_2.c
	@echo "Compiling sort_methods_2.c"
	@$(CC) $(CFLAGS) -c src/algorithm/sort_methods_2.c -o src/algorithm/sort_methods_2.o

src/free/frees.o: src/free/frees.c
	@echo "Compiling frees.c"
	@$(CC) $(CFLAGS) -c src/free/frees.c -o src/free/frees.o

src/lists/aux_lists.o: src/lists/aux_lists.c
	@echo "Compiling aux_lists.c"
	@$(CC) $(CFLAGS) -c src/lists/aux_lists.c -o src/lists/aux_lists.o

src/lists/aux_lists_2.o: src/lists/aux_lists_2.c
	@echo "Compiling aux_lists_2.c"
	@$(CC) $(CFLAGS) -c src/lists/aux_lists_2.c -o src/lists/aux_lists_2.o

src/movements/push.o: src/movements/push.c
	@echo "Compiling push.c"
	@$(CC) $(CFLAGS) -c src/movements/push.c -o src/movements/push.o

src/movements/reverse_rotate.o: src/movements/reverse_rotate.c
	@echo "Compiling reverse_rotate.c"
	@$(CC) $(CFLAGS) -c src/movements/reverse_rotate.c -o src/movements/reverse_rotate.o

src/movements/rotate.o: src/movements/rotate.c
	@echo "Compiling rotate.c"
	@$(CC) $(CFLAGS) -c src/movements/rotate.c -o src/movements/rotate.o

src/movements/swap.o: src/movements/swap.c
	@echo "Compiling swap.c"
	@$(CC) $(CFLAGS) -c src/movements/swap.c -o src/movements/swap.o

src/parse/aux_atoi.o: src/parse/aux_atoi.c
	@echo "Compiling aux_atoi.c"
	@$(CC) $(CFLAGS) -c src/parse/aux_atoi.c -o src/parse/aux_atoi.o

src/parse/aux_strcpy_int.o: src/parse/aux_strcpy_int.c
	@echo "Compiling aux_strcpy_int.c"
	@$(CC) $(CFLAGS) -c src/parse/aux_strcpy_int.c -o src/parse/aux_strcpy_int.o

src/parse/init.o: src/parse/init.c
	@echo "Compiling init.c"
	@$(CC) $(CFLAGS) -c src/parse/init.c -o src/parse/init.o

src/parse/parse.o: src/parse/parse.c
	@echo "Compiling parse.c"
	@$(CC) $(CFLAGS) -c src/parse/parse.c -o src/parse/parse.o

src/pruebas/pruebas.o: src/pruebas/pruebas.c
	@echo "Compiling pruebas.c"
	@$(CC) $(CFLAGS) -c src/pruebas/pruebas.c -o src/pruebas/pruebas.o

# Limpiar archivos objeto
clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -C lib clean
	@echo $(COLOR_VERDE) "All objects cleaned" $(COLOR_RESET)

# Limpiar todo
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C lib fclean
	@echo $(COLOR_VERDE) "All executable cleaned" $(COLOR_RESET)

# Recompilar todo
re: fclean all

# Compilar la librería
$(LIBFT):
	@$(MAKE) -C lib

.PHONY: all clean fclean re

