/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:31:23 by pboonpro          #+#    #+#             */
/*   Updated: 2023/05/21 17:31:23 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_arr *a)
{
	int	temp;
	int	i;

	temp = a->stack[0];
	i = 0;
	while (i < a->top)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = temp;
}

void	ra(t_arr *arr_a)
{
	rotate(arr_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_arr *arr_b)
{
	rotate(arr_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_arr *arr_a, t_arr *arr_b)
{
	rotate(arr_a);
	rotate(arr_b);
	ft_putendl_fd("rr", 1);
}
