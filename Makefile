# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 13:37:42 by bwang-do          #+#    #+#              #
#    Updated: 2017/12/14 12:03:56 by bwang-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean norme normelib

CC = gcc

NAME = fillit

SRC = ft_convert.c \
	  ft_realloc.c \
	  ft_print_controller.c \
	  ft_print_s.c \
	  ft_base.c \
	  ft_printf.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) ft.h
	make -C ./libft/ all
	$(CC) -o $@ $(OBJ) -L ./libft/ -lft

%.o : %.c ft.h
	$(CC) -c $<  

clean:
	/bin/rm -f $(OBJ)
	make  -C ./libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make  -C ./libft/ fclean

norme : 
	norminette $(SRC)
	norminette ft.h

normelib :
	make -C ./libft/ norme

re: fclean all
