#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	search_and_replace(char *str, char to_search, char replace)
{
	while (*str)
	{
		if (*str == to_search)
		{
			ft_putchar(replace);
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
	}

}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		ft_putchar('\n');
	}
	else 
	{
		if (argv[2][1] || argv[3][1])
		{
			ft_putchar('\n');
		}
		else
		{
			search_and_replace(argv[1], argv[2][0], argv[3][0]);
			ft_putchar('\n');
		}
	}
	return (0);
}
