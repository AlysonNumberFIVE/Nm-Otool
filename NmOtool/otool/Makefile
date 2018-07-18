# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 12:07:54 by angonyam          #+#    #+#              #
#    Updated: 2018/07/18 15:55:03 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_otool

SRC = is_32_or_64.c backit_iter.c iterate_through_load_commands.c \
	  otool32.c otool.c otool64.c otool_symbols.c print_functions2.c \
	  print_functions.c read_file.c so.c so2.c so3.c endswith.c meta.c

OBJ = is_32_or_64.o  backit_iter.o iterate_through_load_commands.o \
	  otool32.o otool.o otool64.o otool_symbols.o print_functions2.o \
	  print_functions.o read_file.o so.o so2.o so3.o endswith.o meta.o

LIB = libft/libft.a

all:
	make -C libft
	gcc -g -Wall -Werror -Wextra -c $(SRC)
	gcc -o $(EXEC) $(OBJ) $(LIB)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:
	make fclean -C libft
	rm -f $(OBJ)
	rm -f $(EXEC)

re: fclean all

