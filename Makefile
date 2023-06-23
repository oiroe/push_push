# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:27:44 by pboonpro          #+#    #+#              #
#    Updated: 2023/06/24 02:06:49 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = movement/m_push.c movement/m_reverse.c movement/m_rotate.c \
movement/m_swap.c src/meaw.c src/free.c\
src/change_into_index.c src/stack_op.c src/check_input.c src/ft_atol.c\
src/sort_sim.c src/radix_sort.c src/sort_4.c\

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude -g

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
