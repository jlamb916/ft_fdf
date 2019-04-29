# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 22:31:04 by jolam             #+#    #+#              #
#    Updated: 2019/03/03 22:15:11 by jolam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE = libft.h

SRC_PATH = ./srcs/
INC_PATH = ./includes/

SRCS = *.c

OBJS = *.o

SRC = $(addprefix $(SRC_PATH), $(SRCS))
INCLUDE = $(addprefix -I, $(INC_PATH))

GCC = gcc  -g -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(GCC) $(INCLUDE) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
