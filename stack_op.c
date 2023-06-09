/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:51:57 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/08 16:22:06 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errorhand(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	my_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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
