# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharvoz <acharvoz@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 00:27:03 by acharvoz          #+#    #+#              #
#    Updated: 2024/06/11 00:35:36 by acharvoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_print_char.c\
			ft_print_exa.c\
			ft_print_nbr.c\
			ft_print_prct.c\
			ft_print_ptr.c\
			ft_print_str.c\
			ft_print_unsigned.c\
			ft_printf.c\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

: $(OBJS)
	ar rcs $@ $(OBJS)
bonus: $(OBJS)
	ar rcs $(NAME) $(OBJS)
all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) 

re: fclean all

.PHONY: all clean fclean re