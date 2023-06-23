/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:31:26 by pboonpro          #+#    #+#             */
/*   Updated: 2023/05/21 17:31:26 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_bottom(t_arr *a, int num)
{
	int	i;

	if (a->top >= a->size - 1 || !a)
		return ;
	a->top += 1;
	i = a->top;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = num;
}

int	pop_from_bottom(t_arr *a)
{
	int	temp;
	int	i;

	if (a->top <= -1 || !a)
		return (0);
	temp = a->stack[0];
	i = 1;
	while (i <= a->top)
	{
		a->stack[i - 1] = a->stack[i];
		i++;
	}
	a->top -= 1;
	return (temp);
}

void	pa(t_arr *a, t_arr *b)
{
	int	temp;

	temp = pop_from_bottom(b);
	push_from_bottom(a, temp);
	ft_putendl_fd("pa", 1);
}

void	pb(t_arr *a, t_arr *b)
{
	int	temp;

	temp = pop_from_bottom(a);
	push_from_bottom(b, temp);
	ft_putendl_fd("pb", 1);
}
