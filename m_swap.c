/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:31:19 by pboonpro          #+#    #+#             */
/*   Updated: 2023/05/21 17:31:19 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_arr *a, int index1, int index2)
{
	int	temp;

	temp = a->stack[index1];
	a->stack[index1] = a->stack[index2];
	a->stack[index2] = temp;
}

void	sa(t_arr *arr_a)
{
	swap(arr_a, 0, 1);
	ft_putendl_fd("sa", 1);
}

void	sb(t_arr *arr_b)
{
	swap(arr_b, 0, 1);
	ft_putendl_fd("sb", 1);
}

void	ss(t_arr *arr_a, t_arr *arr_b)
{
	swap(arr_a, 0, 1);
	swap(arr_b, 0, 1);
	ft_putendl_fd("ss", 1);
}
