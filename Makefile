# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paboutel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 14:09:54 by paboutel          #+#    #+#              #
#    Updated: 2020/02/19 14:25:04 by paboutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# FILES
NAME	= libftprintf.a
SRC		= main.c ft_atoi.c ft_hexa.c ft_printchar.c ft_printstr.c ft_printunsigned.c ft_put.c 
OBJ		= $(SRC:.c=.o)

$(NAME): $(OBJ) ft_printf.h
	ar rcs $@ $^

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
