#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int main()
{
	int	i[] = {2, 1, 7, 4, 6, 5, 3};
	sort_int_tab(i, 7);
	int	j;
	j = 0;
	while (j < 7)
	{
		printf("%d\n", i[j]);
		j++;
	}
	return (0);
}
