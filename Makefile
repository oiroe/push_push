# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:27:44 by pboonpro          #+#    #+#              #
#    Updated: 2023/06/06 16:29:53 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_atoi.c ft_putendl_fd.c ft_split.c ft_substr.c \
m_push.c m_reverse.c m_rotate.c m_swap.c meaw.c \
sorting.c \

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
