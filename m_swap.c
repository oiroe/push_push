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

void	swap(t_arr *a)
{
	int	temp;

	temp = a->stack[0];
	a->stack[0] = a->stack[1];
	a->stack[1] = temp;
}

void	sa(t_arr *arr_a)
{
	swap(arr_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_arr *arr_b)
{
	swap(arr_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_arr *arr_a, t_arr *arr_b)
{
	swap(arr_a);
	swap(arr_b);
	ft_putendl_fd("ss", 1);
}
