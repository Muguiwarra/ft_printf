# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabboune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 04:48:50 by nabboune          #+#    #+#              #
#    Updated: 2022/11/10 00:33:25 by nabboune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

BONUS_FILES =	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS = $(BONUS_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

bonus : $(BONUS) $(NAME)
	ar -rc $(NAME) $(BONUS) $(OBJS)

clean :
	$(RM) $(OBJS) $(BONUS)

fclean : clean
	$(RM) ../libft.a

re : fclean all

.PHONY : all clean fclean re
