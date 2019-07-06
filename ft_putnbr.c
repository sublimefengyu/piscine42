#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr1(int number)
{
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
	}

	int reverse = 0;
	while (number > 0)
	{
		reverse = reverse * 10 + number % 10;
		number = number / 10;
	}
	
	while (reverse > 0)
	{
		ft_putchar(reverse % 10 + '0');
		reverse = reverse / 10;
	}
}

void	ft_putnbr_recursive(int number)
{
	if (number > 0)
	{
		ft_putnbr_recursive(number / 10);
		ft_putchar(number % 10 + '0');
	}
}

void	ft_putnbr(int number)
{
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
	}

	if (number == 0)
	{
		ft_putchar('0');
	}
	
	ft_putnbr_recursive(number);
}

int	main(void)
{
	ft_putnbr(-12345);
	ft_putchar('\n');
	ft_putnbr(-1234);
	ft_putchar('\n');
	ft_putnbr(-123);
	ft_putchar('\n');
	ft_putnbr(-12);
	ft_putchar('\n');
	ft_putnbr(-0);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(12);
	ft_putchar('\n');
	ft_putnbr(123);
	ft_putchar('\n');
	ft_putnbr(1234);
	ft_putchar('\n');
	ft_putnbr(12345);
	ft_putchar('\n');
	return 0;
}
