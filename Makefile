# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrafai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 20:10:41 by yrafai            #+#    #+#              #
#    Updated: 2024/12/04 20:10:43 by yrafai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c \
      format_count_utils.c \
      format_utilities.c\
      handle_format.c\
      char_writer.c \
      format_parser.c \
			print_helpers.c \
			printf_helper_herlper.c

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)

$(LIBFT):
	make -C libft
	cp $(LIBFT) .
	mv libft.a $(NAME)

bonus: $(LIBFT) $(OBJ)

%.o: %.c ft_printf.h
	cc $(FLAGS) -c $< -o $@ -I.
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean
