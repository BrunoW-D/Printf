# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 13:37:42 by bwang-do          #+#    #+#              #
#    Updated: 2018/03/07 17:22:18 by bwang-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean norme normelib

CC = gcc

NAME = fillit

SRC = ft_convert.c \
	  ft_realloc.c \
	  ft_realloc_free.c \
	  ft_wchar_to_char.c \
	  ft_print_controller.c \
	  ft_base.c \
	  ft_nchar.c \
	  ft_printf.c \
	  ft_print_s.c \
	  ft_print_c.c \
	  ft_print_d.c \
	  ft_print_o.c \
	  ft_print_x.c \

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
	make  -C ./libft/ fclean

fclean: clean
	/bin/rm -f $(NAME)

norme : 
	norminette $(SRC)
	norminette ft.h

normelib :
	make -C ./libft/ norme

re: fclean all
