# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chajjar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 23:50:06 by chajjar           #+#    #+#              #
#    Updated: 2022/05/18 23:51:43 by chajjar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

DANGER = $(FLAGS) -fsanitize=address -g3

PRINT = ./ft_printf/
LIB_NAME = ftprintf
LIB = -L$(PRINT) -l$(LIB_NAME)

CLIENT = client
C_SRC = client.c gearbox.c
C_OBJ = $(C_SRC:.c=.o)

SERVER = server
S_SRC = server.c gearbox.c
S_OBJ = $(S_SRC:.c=.o)

all: dependency $(CLIENT) $(SERVER)

.c.o:
	@gcc $(FLAGS) -o $@ -c $<

dependency:
	@make -C $(PRINT)

$(CLIENT): $(C_OBJ)
	@gcc $(DANGER) $(LIB) -o $(CLIENT) $(C_OBJ)

$(SERVER): $(S_OBJ)
	@gcc $(DANGER) $(LIB) -o $(SERVER) $(S_OBJ)

clean:
	@rm -f $(C_OBJ) $(S_OBJ)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

aclean: fclean
	@make fclean -C $(PRINT)

re: aclean all

.PHONY: all dependency clean fclean aclean re
