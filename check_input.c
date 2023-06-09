/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:41:05 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/09 00:22:21 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '\0')
		return (0);
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_isdup(long check, char **temp, int i)
{
	i++;
	while (temp[i])
	{
		if (ft_atoi(temp[i]) == check)
			return (1);
		i++;
	}
	return (0);
}

void	do_check(char **temp, int i)
{
	long	check;

	if (temp[0] == (void *)0)
		errorhand("Error");
	while (temp[i])
	{
		check = ft_atol(temp[i]);
		if (!check_isnum(temp[i]))
			errorhand("Error");
		if (check_isdup(check, temp, i))
			errorhand("Error");
		if (check < -2147483648 || check > 2147483647)
			errorhand("Error");
		i++;
	}
}

void	check_input(int ac, char **av)
{
	int		i;
	char	**temp;

	i = 0;
	if (ac == 2)
		temp = ft_split(av[1], ' ');
	else
	{
		i = 1;
		temp = av;
	}
	do_check(temp, i);
	if (ac == 2)
		my_free(temp);
}
