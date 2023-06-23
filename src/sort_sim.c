/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:23:27 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/24 02:01:54 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_arr *stack)
{
	int	min;
	int	i;

	i = 0;
	min = stack->stack[0];
	while (i <= stack->top)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	get_max(t_arr *stack)
{
	int	max;
	int	i;

	i = 0;
	max = stack->stack[0];
	while (i <= stack->top)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

void	sort_3(t_arr *stack)
{
	int	max;

	if (is_sort(stack))
		return ;
	max = get_max(stack);
	if (stack->top == 0)
		return ;
	else if (stack->top == 1)
	{
		if (stack->stack[0] > stack->stack[1])
			ra(stack);
	}
	else if (stack->top == 2)
	{
		if (stack->stack[0] == max)
			ra(stack);
		if (stack->stack[1] == max)
			rra(stack);
		if (stack->stack[0] > stack->stack[1])
			sa(stack);
	}
}

void	sort_5_pushto_b(t_arr *a, t_arr *b, int max, int min)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (a->stack[0] == max || a->stack[0] == min)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	sort_5(t_arr *a, t_arr *b)
{
	int	max;
	int	min;

	if (is_sort(a) || a->size > 5)
		return ;
	max = get_max(a);
	min = get_min(a);
	sort_5_pushto_b(a, b, max, min);
	sort_3(a);
	pa(a, b);
	if (a->stack[0] > a->stack[1])
		ra(a);
	pa(a, b);
	if (a->stack[0] > a->stack[1])
		ra(a);
}
