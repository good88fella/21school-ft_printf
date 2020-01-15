# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktimika <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 18:32:35 by ktimika           #+#    #+#              #
#    Updated: 2019/10/20 18:32:38 by ktimika          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = apply_width_and_accuracy.c fill_arrays.c ft_putchar.c ft_strjoin.c\
    ft_wstrlen_acc.c long_arithmetic.c ft_atoi.c ft_putnbr.c ft_strlen.c\
    get_float_number.c print_string_or_char.c check_type.c ft_bzero.c\
    ft_putwchar.c ft_strnew.c get_integer_digit.c what_is_it.c ft_printf.c\
    ft_putwstr.c ft_tolowercase.c get_params.c apply_flags.c concat_parts.c\
    ft_strchr.c ft_wstrlen.c get_unsigned_num.c float_accuracy_comparision.c\
    ft_strcmp.c

HEADER = -I .

OBJ = $(subst .c,.o,$(SRC))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) $(HEADER) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
