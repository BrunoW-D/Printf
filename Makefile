# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 13:37:42 by bwang-do          #+#    #+#              #
#    Updated: 2018/03/19 18:07:42 by bwang-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean norme normelib

CC = gcc

LDFLAGS = -L ./libft/ -l lft

NAME = libftprintf.a

SRC = ft_convert.c \
	  ft_realloc.c \
	  ft_realloc_free.c \
	  ft_wchar_to_char.c \
	  ft_print_controller.c \
	  ft_base.c \
	  ft_nchar.c \
	  new_itoa.c \
	  ft_utoa.c \
	  ft_printf.c \
	  ft_print_s.c \
	  ft_print_ls.c \
	  ft_print_c.c \
	  ft_print_lc.c \
	  ft_print_d.c \
	  ft_print_ld.c \
	  ft_print_o.c \
	  ft_print_lo.c \
	  ft_print_x.c \
	  ft_print_lx.c \
	  ft_print_u.c \
	  ft_print_lu.c \
	  ft_print_p.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) ft.h
	make -C ./libft/ all
	ar rc $(NAME) $?
	ranlib $(NAME)

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
