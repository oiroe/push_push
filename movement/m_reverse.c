/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:31:04 by pboonpro          #+#    #+#             */
/*   Updated: 2023/05/10 19:31:04 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_arr *a)
{
	int	temp;
	int	i;

	temp = a->stack[a->top];
	i = a->top;
	while (i > -1)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = temp;
}

void	rra(t_arr *arr_a)
{
	reverse(arr_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_arr *arr_b)
{
	reverse(arr_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_arr *arr_a, t_arr *arr_b)
{
	reverse(arr_a);
	reverse(arr_b);
	ft_putendl_fd("rrr", 1);
}
