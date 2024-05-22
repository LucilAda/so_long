# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 10:19:53 by lufreder          #+#    #+#              #
#    Updated: 2024/05/22 14:04:28 by lufreder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

# Liste des fichiers source (.c) pour ft_printf
SRC = src/ft_printf.c src/ft_putchar.c src/ft_putnbr_hex_ptr.c src/ft_putnbr_hex_xlo.c src/ft_putnbr_hex_xup.c src/ft_putnbr_u.c src/ft_putnbr.c src/ft_putptr.c src/ft_putstr.c

# Conversion des fichiers source en fichiers objet (.o)
OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Règle par défaut
all: $(NAME)

# Création de la librairie
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Compilation des fichiers source
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I ${HEADER}

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJS)

# Nettoyage complet (y compris la librairie)
fclean: clean
	@rm -f $(NAME)

# Refaire tout
re: fclean all
