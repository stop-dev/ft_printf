# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stopping <stopping@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 22:11:57 by stopping          #+#    #+#              #
#    Updated: 2021/01/07 21:48:23 by stopping         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
HNAME	= libftprintf.h

FLAGS	= -Wall -Werror -Wextra

LIBDIR	= libft/
LIBNAME = $(LIBDIR)libft.a

SRC	= ft_printf.c ft_print_types.c ft_printf_utils.c

LIB_OBJ = $(LIBDIR)*.o
OBJ	= $(SRC:.c=.o)

all: $(NAME)	

$(NAME): $(OBJ) $(HNAME)
	cd $(LIBDIR) && make && cd ..
	ar -rcs $(NAME) $(OBJ) $(LIB_OBJ)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	cd $(LIBDIR)
	rm -f $(LIB_OBJ)
	cd ..

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR)
	rm -f $(LIBNAME)
	cd ..

re: fclean all

.PHONY: all clean fclean re