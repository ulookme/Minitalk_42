# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chajjar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 21:57:38 by chajjar           #+#    #+#              #
#    Updated: 2022/03/24 10:37:28 by chajjar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_format.c\
   	   ft_printhexa.c\
   	   ft_search.c\
	   ft_base10.c\
	   ft_printf.c\
	   ft_put_elem.c\
	   ft_search2.c\
	   ft_base16.c\
	   ft_read.c\
	   ft_str_elem.c\

OBJECT = $(SRCS:.c=.o)

.c.o :
	  	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME): 	$(OBJECT) 
			@ar rcs $(NAME)  $(OBJECT) 


clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean bonus
