# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabboune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 23:10:26 by marvin            #+#    #+#              #
#    Updated: 2022/11/10 00:30:22 by nabboune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		ft_putadd.c \
		ft_putlhexa.c \
		ft_putuhexa.c \
		ft_putunsi.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	cd libft && $(MAKE)
	ar -rc $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	cd libft && $(MAKE) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
