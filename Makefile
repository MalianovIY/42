# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 23:48:56 by ahorker           #+#    #+#              #
#    Updated: 2019/01/13 22:10:02 by ahorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
OPT = -I. $(HEADER)
NAME = fillit
HEADER = ./fillit.h
SRC = $(fillit.c int2tetra.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): make -C /libft
    $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) $(OPT) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
