# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 12:54:12 by pabastid          #+#    #+#              #
#    Updated: 2022/11/14 12:50:57 by pabastid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

SRC =	ft_print_char.c \
		ft_print_digits.c \
		ft_print_str.c \
		ft_print_hexa_low.c \
		ft_print_hexa_up.c \
		ft_print_pointers.c \
		ft_print_unsigned.c \
		ft_printf.c
		
CC = gcc
OBJ = $(SRC:%.c=%.o)

DEPS = $(SRC:%.c=%.d) 

CFLAGS = -Wall -Wextra -Werror -MMD

RM = rm -f

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

-include $(DEPS)

$(NAME) : $(OBJ) $(HEADER)
	ar -crs	$(NAME) $(OBJ)

clean :
	$(RM) $(OBJ) 
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME) 
	
re : fclean all

.PHONY : all clean fclean re
