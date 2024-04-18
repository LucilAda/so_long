# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:41:03 by lufreder          #+#    #+#              #
#    Updated: 2024/04/18 16:25:52 by lufreder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
# Name of the program to be created

SRC := /so_long /get_next_line/get_next_line.c 
	/get_next_line/get_next_line_utils.c
OBJ := $(SRC:.c=.o)
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

HEADERS = -Iheaders

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -c $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) -Llibft -lft -o $@

clean:
	@make clean -c ./libft
	rm -f $(OBJ)

# Cleaning up the program and object files
fclean: clean
	make clean -C $(MINILIBX)
	rm -f $(NAME)

# Rebuilding the project
re: fclean all

# Debugging the code
debug:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g3 -fsanitize=address
