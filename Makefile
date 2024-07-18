# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:41:03 by lufreder          #+#    #+#              #
#    Updated: 2024/07/18 16:14:44 by lufreder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRC := src/main.c src/map_check.c src/on_the_map.c src/errors.c src/game_init.c \
	src/play.c src/graphics.c src/walls_collectibles_pce.c \

OBJ_DIR := object
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADER := headers/so_long.h
HEADERS := -Iheaders

MLX_DIR := minilibx_opengl_20191021
LIBRARY := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror $(HEADERS)

.PHONY: all clean fclean re debug libft libmlx

all: $(NAME)

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) | libmlx
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

libmlx:
	@echo "Making libmlx"
	@make -C $(MLX_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

debug: CFLAGS += -g3 -fsanitize=address
debug: $(NAME)
