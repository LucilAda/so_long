# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 14:49:06 by lufreder          #+#    #+#              #
#    Updated: 2024/07/18 15:50:04 by lufreder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strcmp.c ft_strrchr.c \
	ft_strcpy.c ft_strncmp.c ft_memchr.c ft_atoi.c ft_strnstr.c ft_memcmp.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c get_next_line_utils.c \
	ft_printf.c ft_putchar.c ft_putnbr_hex_ptr.c ft_putnbr_hex_xlo.c \
	ft_putnbr_hex_xup.c ft_putnbr_u.c ft_putnbr.c ft_putptr.c ft_putstr.c

BSRC = ft_lstnew.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstsize.c \
	ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs ${NAME} ${OBJ}
	
bonus : $(OBJ) $(BOBJ)
	@$ AR -r $(NAME) $?

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

clean:
	@rm -f $(OBJ) $(BOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re