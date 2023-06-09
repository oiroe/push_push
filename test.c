# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdio.h>
//#include "push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	errorhand(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		ft_only_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_number_availability(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	errorhand("Error");
}

void	ft_valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				errorhand("Error");
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			errorhand("Error");
		i++;
	}
}

int		ft_validation(int argc, char **argv)
{
	int i;
	int ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_only_spaces(argv[i]))
		{
			ft_number_availability(argv[i]);
			ft_valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

/*bubble sort but more easy to read*/
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

int main(int ac, char **av)
{
	/*int	i[] = {2, 1, 7, 4, 6, 5, 3};
	sort_int_tab(i, 7);
	int	j;
	j = 0;
	while (j < 7)
	{
		printf("%d\n", i[j]);
		j++;
	}
	char str[] = "2146";
	printf("%d\n", ft_strncmp("-2147483648", str, 12));*/
	if (ft_validation(ac, av))
		printf("good\n");
	else
		printf("bad\n");

	return (0);
}
