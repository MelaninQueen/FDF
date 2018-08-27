# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 12:26:38 by nnqisha           #+#    #+#              #
#    Updated: 2018/08/26 10:51:37 by nnqisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c read.c draw.c ft_sketch.c
OBJ = main.o read.o draw.o ft_sketch.o
LIB = libft/libft.a

FLAG = -lmlx -lm -L libft/ -lft -framework opengl -framework appkit

ERROR = -Werror -Wall -Wextra

all:
	@make -C ./libft
	@gcc $(ERROR) -I $(LIB) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(FLAG)

clean:
	$(MAKE) -C ./libft clean
	@rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./libft fclean
	@rm -f $(LIB)
	@rm -f $(NAME)

re: fclean lib all

lib:
	$(MAKE) -C ./libft all
