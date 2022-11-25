# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francois <francois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 17:46:07 by francois          #+#    #+#              #
#    Updated: 2022/11/25 20:48:36 by francois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror 
SRCS = ft_printf.c ft_utils.c
OBJS = ${SRCS:.c=.o}


all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean : 
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)
	
re : fclean all

.PHONY: all, clean, fclean, re