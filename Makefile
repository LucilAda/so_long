# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:41:03 by lufreder          #+#    #+#              #
#    Updated: 2024/04/15 16:54:02 by lufreder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
# Name of the program to be created

INCLUDES = -I/opt/X11/include -Imlx

SRCDIR = ./so_long
# Directories where source files are located

SRC = $(shell find . -type f -name '*.c')
# Collecting all .c source files within the specified directories

OBJ = $(SRC:.c=.o)
# Generating object file names

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH - mlx\

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

# Regular version of the program
all: subsystems $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Bonus version of the program
bonus: bonus_$(NAME)

bonus_$(NAME): $(OBJ:.o=.bonus.o)
	$(CC) $(CFLAGS) -o $@ $^

# Object files for the bonus version of the program
$(OBJ:.o=.bonus.o): %.bonus.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compiling each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	# $(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)

# Cleaning up object files
clean:
	rm -f $(OBJ) $(OBJ:.o=.bonus.o)

# Cleaning up the program and object files
fclean: clean
	rm -f $(NAME)

# Rebuilding the project
re: fclean all

# Debugging the code
debug:
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME) -g3 -fsanitize=address

.PHONY: all clean fclean re