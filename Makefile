# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:27:44 by pboonpro          #+#    #+#              #
#    Updated: 2023/06/09 00:36:13 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = movement/m_push.c movement/m_reverse.c movement/m_rotate.c \
movement/m_swap.c meaw.c \
change_into_index.c stack_op.c check_input.c ft_atol.c\

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
