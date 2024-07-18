# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:41:03 by lufreder          #+#    #+#              #
#    Updated: 2024/07/18 10:54:25 by lucilla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
# Name of the program to be created

SRC := src/main.c src/map_check.c src/on_the_map.c src/errors.c src/game_init.c \
	src/play.c src/graphics.c src/walls_collectibles_pce.c \
	../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
OBJ := $(SRC:.c=.o)
# OBJ := $(notdir $(SRC:.c=.o))
HEADER = headers/so_long.h headers/get_next_line.h
HEADERS = -Iheaders

MLX_DIR := minilibx_opengl_20191021
LIBRARY := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft

FT_PRINTF_DIR = ft_printf
FT_PRINTF = -L$(FT_PRINTF_DIR) -lftprintf

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADERS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
# $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.a ft_printf.a
	@echo "Making in $(MLX_DIR)"
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) $(LIBFT) $(FT_PRINTF) -o $(NAME)

libft.a:
	@echo "Making in $(LIBFT_DIR)"
	@make -C $(LIBFT_DIR)
	@touch libft.a

ft_printf.a:
	@echo "Making in $(FT_PRINTF_DIR)"
	@make -C $(FT_PRINTF_DIR)
	@touch ft_printf.a


clean:
	@make clean -C ./libft 
	@make clean -C ./ft_printf
	@make clean -C ./minilibx_opengl_20191021
	@rm -f $(OBJ)

# Cleaning up the program and object files
fclean: clean
	@make fclean -C ./libft 
	@make fclean -C ./ft_printf
	@make clean -C ./minilibx_opengl_20191021
	@rm -f $(NAME)
	@rm -f libft.a ft_printf.a

# Rebuilding the project
re: fclean clean all

# Debugging the code
debug:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g3 -fsanitize=address

		
# $(NAME) : $(OBJ)
# 	@echo "Making in $(LIBFT_DIR)"
# 	@make -C $(LIBFT_DIR)
# 	@echo "Making in $(FT_PRINTF_DIR)"
# 	@make -C $(FT_PRINTF_DIR)
# 	@echo "Making in $(MLX_DIR)"
# 	@make -C $(MLX_DIR)
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) $(LIBFT) $(FT_PRINTF) -o $(NAME) 
# @make -c $(MLX_DIR)
# @$(CC) $(CFLAGS) $(OBJ) $(MLX_DIR) -Llibft -lft -o $@