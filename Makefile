# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 17:33:25 by fdibbert          #+#    #+#              #
#    Updated: 2019/05/03 19:54:32 by fdibbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

SRCS = main.c get_next_line.c get_color.c draw.c drawing.c additional_stuff.c iso.c key_hook.c \
		mouse_hook.c increment_xyz.c identify_xyz.c

OBJ = $(SRCS:.c=.o)

INC = get_next_line.h libft/libft.h

FLAGS = -Wall -Wextra -Werror

.PHONY : all, re, clean, flcean

all: $(NAME)

$(NAME) :
	@make -C libft/
	@gcc $(FLAGS) -I $(INC) -c $(SRCS)
	@gcc $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all