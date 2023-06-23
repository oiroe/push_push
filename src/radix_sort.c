/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:47:04 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/23 20:51:34 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bit(t_arr *a)
{
	int	i;
	int	max;
	int	max_bit;

	i = 0;
	max = a->stack[0];
	while (i <= a->top)
	{
		if (a->stack[i] > max)
			max = a->stack[i];
		i++;
	}
	max_bit = 0;
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_arr *a, t_arr*b)
{
	int	i;
	int	j;
	int	temp;
	int	size;
	int	most_bit;

	most_bit = max_bit(a);
	size = a->size;
	i = 0;
	while (i < most_bit)
	{
		j = 0;
		while (j < size)
		{
			temp = a->stack[0];
			if ((temp >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (!is_empty(b))
			pa(a, b);
		i++;
	}
}
