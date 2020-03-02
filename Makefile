# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 15:45:19 by raguillo          #+#    #+#              #
#    Updated: 2020/01/24 15:45:25 by raguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./
INC_PATH = ./includes ./libft/include
GCC_FLGS = -Werror -Wextra -Wall

SRC_NAME = main.c fractol.c draw.c hook.c burningship.c julia.c mandelbrot.c

GCC_LIBS = -lmlx -framework OpenGL -framework Appkit

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH), $(LIB_NAME))

all: $(NAME)
	
$(NAME): $(OBJ)
		make -C $(LIB_PATH)libft
			$(CC) $(LIB) -lft $(INC) $(OBJ) $(GCC_LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
			$(CC)  $(INC) -o $@ -c $<

clean:
		rm -fv $(OBJ)
			make -C $(LIB_PATH)libft clean


fclean: clean
		make -C $(LIB_PATH)libft fclean
			rm -fv $(NAME)

re: fclean all
