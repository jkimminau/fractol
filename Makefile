# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 17:12:40 by jkimmina          #+#    #+#              #
#    Updated: 2018/08/17 14:32:53 by jkimmina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	./src/main.c		\
		./src/init.c		\
		./src/draw.c		\
		./src/view.c		\
		./src/key.c		\
		./src/mouse.c		\
		./src/color.c		\
		./src/color2.c	\
		./src/mandelbrot.c\
		./src/julia.c		\
		./src/burningship.c

OBJ =	$(SRC:.c=.o)

HEADERDIR = .

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
LIBFTLINK = -L./libft/ -lft

LIBMLX = ./minilibx/libmlx.a
LIBMLXLINK = -L./minilibx/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

libft: $(LIBFT)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC) -I$(HEADERDIR)
	@mv *.o ./src

$(LIBFT):
	make -C ./libft

libmlx: $(LIBMLX)

$(LIBMLX): 
	make -C ./minilibx/

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LIBFTLINK) $(LIBMLXLINK)

clean:
	/bin/rm -f $(OBJ) $(HEADER:.h=.h.gch)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/
	make clean -C minilibx/

re: fclean all
