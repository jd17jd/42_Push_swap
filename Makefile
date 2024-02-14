# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:03:30 by jvivas-g          #+#    #+#              #
#    Updated: 2024/02/14 22:29:43 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Colores
COLOR_RESET = "\033[0m"
COLOR_VERDE = "\033[32m"

# Directorios de origen
SRC = src

# Lista de archivos fuente
SOURCES := $(wildcard $(SRC)/*.c) $(wildcard $(SRC)*/*/*.c)


# Libreria
LIBFT = lib/libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Creación de objetos
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

# Reglas de compilación
%.o: %.c
	@echo "Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Reglas principales
$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) -L lib -lft -o $(NAME)
	@echo $(COLOR_VERDE) "Created $(NAME)" $(COLOR_RESET)

all: $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -C lib clean
	@echo $(COLOR_VERDE) "All objects cleaned" $(COLOR_RESET)

fclean: clean
	@$(RM)	$(NAME)
	@$(MAKE) -C lib fclean
	@echo $(COLOR_VERDE) "All executable cleaned" $(COLOR_RESET)

re: fclean all

$(LIBFT):
	@$(MAKE) -C lib

.PHONY: all clean fclean re
