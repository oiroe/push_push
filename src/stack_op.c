/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:51:57 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/23 13:34:05 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_arr *arr, int num)
{
	if (arr->top >= arr->size - 1 || !arr)
		return ;
	arr->top++;
	arr->stack[arr->top] = num;
}

int	pop(t_arr *arr)
{
	int	num;

	if (arr->top <= -1 || !arr)
		return (0);
	num = arr->stack[arr->top];
	arr->top--;
	return (num);
}

int	is_empty(t_arr *a)
{
	if (!a || a->top == -1)
		return (1);
	return (0);
}
