# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 13:15:52 by ngontjar          #+#    #+#              #
#    Updated: 2019/12/01 10:54:51 by ngontjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCES = fdf.c
OBJECTS = $(subst .c,.o,$(SOURCES))
LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror
LINKS = -I libft -L libft \
	-I /usr/local/include -L /usr/local/lib \
	-lmlx -lft -framework OpenGL -framework Appkit

.PHONY: re fclean all

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)
	@echo "\033[38;5;214mDone!\033[0m"

$(OBJECTS): $(LIBFT) $(SOURCES)
	@echo "\033[38;5;214mCompiling...\033[0m"
	@gcc $(FLAGS) -c $(SOURCES)

$(LIBFT):
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJECTS)
	@echo "\033[38;5;214mObjects removed!\033[0m"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "\033[38;5;214mTargets removed!\033[0m"

re: fclean all
	@make -C libft re
