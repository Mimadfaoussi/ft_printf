# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 08:03:22 by mfaoussi          #+#    #+#              #
#    Updated: 2024/01/02 09:55:54 by mfaoussi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
		./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c \
		./libft/ft_putnbr_fd.c ./libft/ft_strdup.c ./libft/ft_strlen.c \
		./print/print_d.c ./print/print_p.c ./print/print_u.c ./print/print_x.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f

all: $(NAME)


$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)


clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY: all clean fclean re