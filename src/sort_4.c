/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:59:44 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/24 02:04:52 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4_pushto_b(t_arr *a, t_arr *b, int min)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (a->stack[0] == min)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	sort_4(t_arr *a, t_arr *b)
{
	int	min;

	if (is_sort(a) || a->size > 4)
		return ;
	min = get_min(a);
	sort_4_pushto_b(a, b, min);
	sort_3(a);
	pa(a, b);
}
