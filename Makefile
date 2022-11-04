# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 22:55:50 by bahbibe           #+#    #+#              #
#    Updated: 2022/11/04 07:52:53 by bahbibe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c\
	ft_ft.c\
	ft_pointer.c\

CC = cc
CFLAGS = -Wall -Wextra -Werror 
OBJ = $(SRC:.c=.o)
all : $(NAME)
$(NAME): $(OBJ)
	ar -r $(NAME) $(OBJ)
fclean : clean
	rm -rf $(NAME)
clean:
	rm -rf $(OBJ)
re:fclean all

