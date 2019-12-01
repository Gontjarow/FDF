# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 13:15:52 by ngontjar          #+#    #+#              #
#    Updated: 2019/12/01 11:12:19 by ngontjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c

SRC2 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC3 = ft_lstnew.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c

SRC4 = ft_islower.c ft_isupper.c ft_isspace.c ft_putstrn.c ft_strrev.c ft_print2dstr.c ft_range.c ft_strlcpy.c ft_putstrn_nulls.c ft_strclen.c ft_lstfree.c ft_lstadd_back.c ft_sqrt_int.c ft_isprime.c ft_prime_nfactors.c ft_prime_factors.c ft_issquare_int.c ft_lcm.c ft_hcf.c ft_itoa_base.c ft_get_next_line.c

SRO1 = $(subst .c,.o,$(SRC1))
SRO2 = $(subst .c,.o,$(SRC2))
SRO3 = $(subst .c,.o,$(SRC3))
SRO4 = $(subst .c,.o,$(SRC4))

TESTSRC = ./test
TESTBIN = ./test/bin

FLAGS = -Wall -Wextra -Werror

.PHONY: re fclean all objects test

all: $(NAME)

$(NAME): $(SRO1) $(SRO2) $(SRO3) $(SRO4)
	@ar -rc $(NAME) $(SRO1) $(SRO2) $(SRO3) $(SRO4)
	@echo "\033[38;5;214mDone!\033[0m"

$(SRO1) $(SRO2) $(SRO3) $(SRO4): $(SRC1) $(SRC2) $(SRC3) $(SRC4)
	@echo "\033[38;5;214mCompiling...\033[0m"
	@gcc $(FLAGS) -c $(SRC1) $(SRC2) $(SRC3) $(SRC4)

re: fclean all

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(TESTBIN)
	@echo "\033[38;5;214mTargets removed!\033[0m"

clean:
	@rm -f $(SRO1) $(SRO2) $(SRO3) $(SRO4)
	@echo "\033[38;5;214mObjects removed!\033[0m"

test: $(NAME)
	@mkdir -p $(TESTBIN)
	@echo "\033[38;5;214mCompiling $(TESTSRC)/$(file).c ...\033[0m"
	@gcc $(FLAGS) $(TESTSRC)/$(file).c -o $(TESTBIN)/$(file) -I. -L. -lft
	@echo "\033[38;5;214mRunning $(TESTBIN)/$(file) ...\033[0m"
	@$(TESTBIN)/$(file)
