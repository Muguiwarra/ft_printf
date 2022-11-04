# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 23:10:26 by marvin            #+#    #+#              #
#    Updated: 2022/11/03 23:10:26 by marvin           ###   ########.fr        #
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
	$(MAKE) $(LIBFT)
	ar -rc $(NAME) $(OBJS)

clean :
	$(MAKE) 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re