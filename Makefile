# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:41:03 by lufreder          #+#    #+#              #
#    Updated: 2024/05/22 14:08:19 by lufreder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
# Name of the program to be created

SRC := src/main.c src/map_check.c src/on_the_map.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
OBJ := $(SRC:.c=.o)

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/
HEADER := headers/so_long.h headers/get_next_line.h
HEADERS := -Iheaders

LIBFT_DIR := libft
LIBFT := -L$(LIBFT_DIR) -lftprintf

FT_PRINTF_DIR := ft_printf
FT_PRINTF := -L$(FT_PRINTF_DIR) -lftprintf

CC := gcc
CFLAGS := -Wall -Wextra -Werror


%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "Making in $(LIBFT_DIR)"
	@make -C $(LIBFT_DIR)
	@echo "Making in $(FT_PRINTF_DIR)"
	@make -C $(FT_PRINTF_DIR)
	@echo "Making in $(MINILIBX)"
	@make -c $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(LIBRARY) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@make clean -C $(MINILIBX)
	@rm -f $(OBJ)

# Cleaning up the program and object files
fclean: clean
# @make fclean -C $(MINILIBX)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	@rm -f $(NAME)

# Rebuilding the project
re: fclean clean all

# Debugging the code
debug:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g3 -fsanitize=address
