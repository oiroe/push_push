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
		errorhand("Error");
	}
	arr->size = n;
	arr->top = -1;
	return (arr);
}

/*t_arr	*init_stack_a(int ac, char **av)
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
} old ver*/

t_arr	*init_stack_a(int ac, char **av)
{
	int		i;
	char	**temp;
	char	*join;
	char	*before;
	char	*del;
	t_arr	*new;

	i = 1;
	join = malloc(sizeof(char *) * 1);
	join[0] = '\0';
	while (i < ac)
	{
		before = ft_strjoin(" ", av[i]);
		del = join;
		join = ft_strjoin(join, before);
		free(before);
		free(del);
		i++;
	}
	temp = ft_split(join, ' ');
	free(join);
	i = 0;
	while (temp[i])
	{
		push(new, ft_atoi(temp[i]));
		i++;
	}
	my_free(temp);
	return (new);
} //error not init stack at first and norm error

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

int main(int ac, char **av)
{
	t_arr	*a;
	t_arr	*b;
	//int		num;

	if (ac == 1)
		return (0);
	check_input(ac, av);
	a = init_stack_a(ac, av);
	b = stack_init(countstr(av[1], ' '));
	//display(a, b);
	change_input_to_index(a);
	display(a, b);
	/*selection_sort(a);
	sa(a);
	display(a, b);
	pb(a, b);
	display(a, b);
	pa(a, b);
	display(a, b);*/
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	return (0);
}
