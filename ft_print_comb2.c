#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnumber_digit2(int number)
{
	int tens = number / 10;
	int units = number % 10;
	ft_putchar(tens + '0');
	ft_putchar(units + '0');
}

void	ft_print_comb2(void)
{
	int i, j;
	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putnumber_digit2(i);
			ft_putchar(' ');
			ft_putnumber_digit2(j);
			if (!(i == 98 && j == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i ++;
	}
}
