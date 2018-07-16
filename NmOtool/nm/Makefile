# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:37:22 by angonyam          #+#    #+#              #
#    Updated: 2018/07/16 12:08:16 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_nm

SRC = main.c read_file.c symbol.c print_functions.c nm64.c nm32.c arc.c \
	  lettering.c

OBJ = main.o read_file.o symbol.o print_functions.o nm64.o nm32.o arc.o \
	  lettering.o

LIB = libft/libft.a

all:
	make -C libft
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -o $(EXEC) $(OBJ) $(LIB)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:
	make fclean -C libft
	rm -f $(OBJ)
	rm -f $(EXEC)

re: fclean all
