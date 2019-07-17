#include <stdio.h>
int ft_iterative_factorial(int nb)
{
	int i;
	int result;

	i = 1;
	result =1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else 
	{
		while (i <=  nb)
		{
			result = result * i;
			i++;
		}
		return (result);
	}
}


int main ()
{
	int nb1 = -12;
	int nb2 = 0;
	int nb3 = 1;
	int nb4 = 4;
	int nb5= 10;

	printf("%d\n", ft_iterative_factorial(nb1));
	printf("%d\n", ft_iterative_factorial(nb2));
	printf("%d\n", ft_iterative_factorial(nb3));
	printf("%d\n", ft_iterative_factorial(nb4));
	printf("%d\n", ft_iterative_factorial(nb5));

	return 0;
}

