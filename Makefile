# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:41:03 by lufreder          #+#    #+#              #
#    Updated: 2024/06/06 17:37:14 by lufreder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
# Name of the program to be created

SRC := src/main.c src/map_check.c src/on_the_map.c \
	../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
OBJ := $(SRC:.c=.o)
# OBJ := $(notdir $(SRC:.c=.o))
HEADER = headers/so_long.h headers/get_next_line.h
HEADERS = -Iheaders

MLX_DIR := minilibx
LIBRARY := -L$(MLX_DIR) -framework OpenGL -framework AppKit

LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft

FT_PRINTF_DIR = ft_printf
FT_PRINTF = -L$(FT_PRINTF_DIR) -lftprintf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "Making in $(LIBFT_DIR)"
	@make -C $(LIBFT_DIR)
	@echo "Making in $(FT_PRINTF_DIR)"
	@make -C $(FT_PRINTF_DIR)
	@echo "Making in $(MLX_DIR)"
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(LIBRARY) -o $(NAME) 
# @make -c $(MLX_DIR)
# @$(CC) $(CFLAGS) $(OBJ) $(MLX_DIR) -Llibft -lft -o $@

clean:
	@make clean -C ./libft 
	@make clean -C ./ft_printf
	@make clean -C ./minilibx
	@rm -f $(OBJ)

# Cleaning up the program and object files
fclean: clean
	@make clean -C $(MLX_DIR)
	@make fclean -C ./libft 
	@make fclean -C ./ft_printf
	@rm -f $(NAME)

# Rebuilding the project
re: fclean clean all

# Debugging the code
debug:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g3 -fsanitize=address
