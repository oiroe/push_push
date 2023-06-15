/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:41:05 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/14 21:46:58 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '\0')
		return (0);
	if (num[i] == '-' || num[i] == '+')
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

void	av_check(char *av)
{
	size_t	i;
	int		count;
	char	*temp;

	temp = av;
	count = 0;
	i = 0;
	while (i < strlen(temp))
	{
		if (ft_isdigit(temp[i]))
				count++;
		i++;
	}
	if (count == 0)
		errorhand("Error");
}

void	check_input(int ac, char **av)
{
	int		i;
	char	**temp;
	char	*join;

	i = 1;
	while (i < ac)
	{
		av_check(av[i]);
		i++;
	}
	join = join_input(ac, av);
	temp = ft_split(join, ' ');
	free(join);
	do_check(temp, 0);
	my_free(temp);
}
