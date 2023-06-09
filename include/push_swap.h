/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:11:25 by pboonpro          #+#    #+#             */
/*   Updated: 2023/05/10 18:11:25 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_arr
{
	int	*stack;
	int	size;
	int	top;
}			t_arr;

int		countstr(char const *s, char c);
t_arr	*init_stack_a(int ac, char **av);
t_arr	*stack_init(unsigned int n);
void	push(t_arr *arr, int num);
int		pop(t_arr *arr);
void	ra(t_arr *arr_a);
void	rb(t_arr *arr_b);
void	rr(t_arr *arr_a, t_arr *arr_b);
void	ft_putendl_fd(char *s, int fd);
void	sa(t_arr *arr_a);
void	sb(t_arr *arr_b);
void	ss(t_arr *arr_a, t_arr *arr_b);
void	rra(t_arr *arr_a);
void	rrb(t_arr *arr_b);
void	rrr(t_arr *arr_a, t_arr *arr_b);
void	pa(t_arr *a, t_arr *b);
void	pb(t_arr *a, t_arr *b);
void	swap(t_arr *a, int index1, int index2);
void	selection_sort(t_arr *a);
void	display(t_arr *arr, t_arr *b);
void	change_input_to_index(t_arr *a);
void	my_free(char **str);
void	errorhand(char *str);
void	check_input(int ac, char **av);
long	ft_atol(const char *str);

#endif
