# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:26:47 by dmendelo          #+#    #+#              #
#    Updated: 2018/11/14 10:24:39 by dmendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror

ASAN = -fsanitize=address -g

SRC = ft_ls.c printing.c long_option.c sort.c options.c list.c read.c \
	  recursion.c free.c

INC = -I . -I libft/

OBJ = ft_ls.o printing.o long_option.o sort.o options.o list.o read.o \
	  recursion.o free.o

all: $(OBJ)
		@make -C libft
		@gcc $(CFLAGS) -c $(SRC) $(INC) $(ASAN)
		@gcc $(CFLAGS) $(ASAN) $(OBJ) libft/libft.a -o $(NAME)

clean:
		@make -C libft clean
		@rm -rf $(OBJ)

fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)

re: fclean all
