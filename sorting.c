/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:18:28 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/06 18:06:33 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackcpy(int *dest, t_arr *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		dest[i] = a->stack[i];
		i++;
	}
}

void	selection_sort(t_arr *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->stack[i] > a->stack[j])
				swap(a, i, j);
			j++;
		}
		i++;
	}
}

void	change_input_to_index(t_arr *a)
{
	int	*temp;
	int	*trash;
	int	i;
	int	j;

	temp = malloc(sizeof(int) * a->size);
	if (!temp)
		return ;
	stackcpy(temp, a);
	selection_sort(a);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (temp[i] == a->stack[j])
			{
				temp[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	trash = a->stack;
	a->stack = temp;
	free(trash);
}
