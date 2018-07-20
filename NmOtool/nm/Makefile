# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:37:22 by angonyam          #+#    #+#              #
#    Updated: 2018/07/20 13:14:52 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_nm

SRC = main.c read_file.c symbol.c print_functions.c nm64.c nm32.c arc.c \
	  lettering.c arraylen.c arraydup.c arraypush.c charpush.c  arc2.c \
	  count_names.c count_names2.c so.c so2.c so3.c endswith.c \
	  free_2d_array.c seg_extract_32.c 

OBJ = main.o read_file.o symbol.o print_functions.o nm64.o nm32.o arc.o \
	  lettering.o arraylen.o arraydup.o arraypush.o charpush.o arc2.o \
	  count_names.o count_names2.o so.o endswith.o so2.o so3.o \
	  free_2d_array.o seg_extract_32.o

LIB = libft/libft.a

all:
	make -C libft
	gcc -c -Wall -Werror -Wextra  $(SRC)
	gcc -g -o $(EXEC) $(OBJ) $(LIB)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:
	make fclean -C libft
	rm -f $(OBJ)
	rm -f $(EXEC)

re: fclean all
