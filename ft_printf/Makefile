# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francois <francois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 17:46:07 by francois          #+#    #+#              #
#    Updated: 2022/12/02 18:14:43 by francois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -c -Wall -Wextra -Werror
INCLUDES = -I./includes
SRCS = ft_printf.c ft_utils.c ft_puthexlen.c ft_printpointer.c ft_putunsignednbr.c
OBJS = ${SRCS:.c=.o}



all: $(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
		ar rcs $(NAME) $(OBJS)

clean : 
		rm -f $(OBJS)
		make clean -C ./libft 

fclean : clean
		rm -f $(NAME)
		rm -f ./libft/libft.a
	
re : fclean all

.PHONY: all, clean, fclean, re
