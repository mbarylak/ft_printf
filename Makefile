# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 19:32:51 by mbarylak          #+#    #+#              #
#    Updated: 2021/11/04 19:58:50 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c utils.c utils2.c

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
