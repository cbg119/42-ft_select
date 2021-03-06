# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 14:40:39 by cbagdon           #+#    #+#              #
#    Updated: 2019/04/11 16:13:29 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = main.c \
		args.c \
		input.c \
		print.c \
		print_utils.c \
		resize.c \
		signal_handler.c

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft
	@gcc $(FLAGS) -g -I $(INCLUDES) -c $(addprefix src/,$(SRC)) $(addprefix builtin/,$(BUILTIN))
	@gcc $(Flags) -g -o $(NAME) $(OBJECTS) -L ./libft/ -lft -ltermcap

clean:
	make -C libft clean
	@rm -rf $(OBJECTS)

fclean: clean
	make -C libft fclean
	@rm -rf $(NAME)

re: fclean all
