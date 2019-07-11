#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int number)
{
	if (number > 0)
	{
		ft_putnbr(number / 10);
		ft_putchar(number % 10 + '0');
	}
}

int		get_number_from_str(char *str)
{
	int nb;

	nb = 0;
	while (*str)
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb);
}


void	print_line(int i, int nb, int result)
{
	ft_putchar(i + '0');
	ft_putchar(' ');
	ft_putchar('x');
	ft_putchar(' ');

	if (nb == 0)
		ft_putchar('0');
	else
		ft_putnbr(nb);

	ft_putchar(' ');
	ft_putchar('=');
	ft_putchar(' ');

	if (nb == 0)
		ft_putchar('0');
	else
		ft_putnbr(result);
	ft_putchar('\n');
}

void	print_solution(int nb)
{
	int	i;
	int	mul;
	
	i = 1;
	mul = 1;
	
	while (i < 10)
	{
		print_line(i, nb, i * nb);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("\n");
	}
	else
	{
		print_solution(get_number_from_str(argv[1]));
	}
	return (0);
}

