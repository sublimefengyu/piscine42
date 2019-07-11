#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int head, int tail)
{
	while (head <= tail)
	{
		ft_putchar(str[head]);
		head ++;
	}
}

int	is_space_word(char c)
{
	return c == ' ' || c == '\t';
}

void	rev_wstr(char *str)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	
	while (str[i])
	{
		i++;
	}

	i--;
	while (i >= 0)
	{
		j = i;
		while (j >= 0 && !is_space_word(str[j]))
		{
			j--;	
		}
		
		if (j == -1)
		{
			ft_putstr(str, 0, i);
			break;
		}
		else
		{
			ft_putstr(str, j + 1, i);
			ft_putchar(str[j]);
			i = j - 1;
		}
	}
}

int		main(int argc, char **argv)
{
	int nb_word;

	if (argc != 2)
	{
		ft_putchar('\n');
	}
	else
	{
		rev_wstr(argv[1]);
		ft_putchar('\n');
	}
	return (0);
}

