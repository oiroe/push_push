# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:27:44 by pboonpro          #+#    #+#              #
#    Updated: 2023/06/07 02:56:13 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = m_push.c m_reverse.c m_rotate.c m_swap.c meaw.c \
sorting.c \

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
