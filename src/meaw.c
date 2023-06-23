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

/*void	display(t_arr *arr, t_arr *b)
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
}*/

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

char	*join_input(int ac, char **av)
{
	int		i;
	char	*join;
	char	*before;
	char	*del;

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
	return (join);
}

t_arr	*init_stack_a(int ac, char **av, int *cc)
{
	int		i;
	int		count;
	char	**temp;
	char	*join;
	t_arr	*new;

	join = join_input(ac, av);
	count = countstr(join, ' ');
	*cc = count;
	temp = ft_split(join, ' ');
	free(join);
	new = stack_init(count);
	i = 0;
	while (temp[i])
	{
		push(new, ft_atoi(temp[i]));
		i++;
	}
	my_free(temp);
	return (new);
}

void	do_sort(t_arr *a, t_arr *b)
{
	/*if (a->size == 3)
		sort_3(a);
	else if (a->size == 5)
		sort_5(a, b);
	else if (a->size >= 100 && a->size < 500)
		quick_sort();
	else if (a->size >= 500)*/
		radix_sort(a, b);
}

int	main(int ac, char **av)
{
	t_arr	*a;
	t_arr	*b;
	int		num;

	if (ac == 1)
		return (0);
	b = NULL;
	check_input(ac, av);
	a = init_stack_a(ac, av, &num);
	if (is_sort(a))
	{
		free_stack(a, NULL);
		return (0);
	}
	b = stack_init(num);
	change_input_to_index(a);
	do_sort(a, b);
	free_stack(a, b);
	return (0);
}
