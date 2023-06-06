/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meaw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:27:22 by pboonpro          #+#    #+#             */
/*   Updated: 2023/05/10 18:27:22 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_arr	*stack_init(unsigned int n)
{
	t_arr	*arr;

	arr = malloc(sizeof(t_arr));
	if (!arr)
		return (0);
	arr->stack = malloc(sizeof(int) * n);
	if (!arr->stack)
	{
		free(arr);
		return (0);
	}
	arr->size = n;
	arr->top = -1;
	return (arr);
}

t_arr	*init_stack_a(int ac, char **av)
{
	int		i;
	char	**temp;
	t_arr	*new;

	i = 0;
	if (ac == 2)
	{
		new = stack_init(countstr(av[1], ' '));
		temp = ft_split(av[1], ' ');
	}
	else
	{
		i = 1;
		temp = av;
		new = stack_init(ac - 1);
	}
	while (temp[i])
	{
		push(new, ft_atoi(temp[i]));
		i++;
	}
	if (ac == 2)
		my_free(temp);
	return (new);
}

void	display(t_arr *arr, t_arr *b)
{
	if(arr->top>=0)
	{
		printf("\nThe elements in STACK A\n");
		for(int i = 0; i <= arr->top; i++)
			printf("%d\n", arr->stack[i]);
		printf("\n");
		printf("\nThe elements in STACK B\n");
		for(int j = 0; j <= b->top; j++)
			printf("%d\n", b->stack[j]);
		printf("\n");
	}
	else
	{
		printf("\n The STACK is empty");
	}
}
// will using check before push into stack
/*int	check_dup(t_arr *a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a->top)
	{
		j = i + 1;
		while (j <= a->top)
		{
			if (a->stack[i] == a->stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_valid(char **av)
{
	int	i;
	int	j;


}

void	check_input(int ac, char **av)
{
	int	i;

	if (ac == 1)
		exit(0);
	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			ft_putendl_fd("error", 2);
			exit(0);
		}
		i++;
	}
}*/

int main(int ac, char **av)
{
	t_arr	*a;
	t_arr	*b;
	//int		num;

	a = init_stack_a(ac, av);
	b = stack_init(countstr(av[1], ' '));
	display(a, b);
	change_input_to_index(a);
	display(a, b);
	//selection_sort(a);
	//sa(a);
	//display(a, b);
	/*pb(a, b);
	display(a, b);
	pa(a, b);
	display(a, b);*/
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	return (0);
}
