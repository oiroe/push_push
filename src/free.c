/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:51:01 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/24 01:18:17 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_arr *a, t_arr *b)
{
	if (a != NULL)
	{
		free(a->stack);
		free(a);
		a = NULL;
	}
	if (b != NULL)
	{
		free(b->stack);
		free(b);
		b = NULL;
	}
}

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
	//str = NULL;
}
