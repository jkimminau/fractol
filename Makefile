# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 17:12:40 by jkimmina          #+#    #+#              #
#    Updated: 2018/06/05 13:59:11 by jkimmina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	main.c		\
		init.c		\
		draw.c		\
		view.c		\
		key.c		\
		mouse.c		\
		color.c		\
		mandelbrot.c\
		julia.c		\
		burningship.c

OBJ =	$(SRC:.c=.o)

HEADER = fractol.h	\
		 init.h		\
		 draw.h		\
		 view.h		\
		 structs.h	\
		 key.h		\

HEADERDIR = ./inc

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
LIBFTLINK = -L./libft/ -lft

LIBMLX = ./minilibx/libmlx.a
LIBMLXLINK = -L./X11_minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

libmlx: $(LIBMLX)

$(LIBMLX): 
	make -C ./X11_minilibx_macos/

$(NAME): $(LIBFT) $(LIBMLX)
	gcc $(FLAGS) -c $(addprefix src/, $(SRC)) -I$(HEADERDIR)
	gcc $(LIBRARY) $(OBJ) -o $(NAME) $(LIBFTLINK) $(LIBMLXLINK)

clean:
	/bin/rm -f $(OBJ) $(HEADER:.h=.h.gch)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/
	make clean -C X11_minilibx_macos/

re: fclean all
