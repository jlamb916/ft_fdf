# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 22:59:31 by jolam             #+#    #+#              #
#    Updated: 2019/03/14 21:56:42 by jolam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c\
	  ft_parse_map.c\
	  ft_store_map.c\
	  ft_init.c\
	  ft_trans.c\
	  ft_draw.c\
	  ft_loop.c\
	  ft_color.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

GCC = gcc -g

LIBFT = ./libft/libft.a

LIBINC = -I ./libft/includes
LIBLINK = -L ./libft -lft

MLX = ./minilibx/libmlx.a
MLXINC = -I ./minilibx
MLXLINK = -L ./minilibx -lmlx -framework OpenGl -framework Appkit

SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/

all: obj libft mlx $(NAME)

obj: 
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(GCC) $(LIBINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

mlx: $(MLX)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(OBJ) $(MLXLINK) $(LIBLINK)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./minilibx clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
