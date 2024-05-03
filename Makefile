# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:41:03 by lufreder          #+#    #+#              #
#    Updated: 2024/04/26 10:56:39 by lucilla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
# Name of the program to be created

SRC := map_check.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ := $(SRC:.c=.o)
#LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
#MINILIBX := minilibx/
#HEADER = headers/so_long.h headers/get_next_line.h
HEADER = -Iheaders

LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lftprintf

FT_PRINTF_DIR = ft_printf
FT_PRINTF = -L$(FT_PRINTF_DIR) -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT_DIR) 
	@make -C $(FT_PRINTF_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
#	@make -c $(MINILIBX)
#	@$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) -Llibft -lft -o $@

clean:
	@make clean -C ./libft 
	@make clean -C ./ft_printf
	@rm -f $(OBJ)

# Cleaning up the program and object files
fclean: clean
#	make clean -C $(MINILIBX)
	@make fclean -C ./libft 
	@make fclean -C ./ft_printf
	@rm -f $(NAME)

# Rebuilding the project
re: fclean all

# Debugging the code
debug:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g3 -fsanitize=address
