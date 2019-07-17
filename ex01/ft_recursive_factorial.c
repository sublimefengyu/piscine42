#include <stdio.h>
int ft_recursive_factorial(int nb)
{
	int result;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else 
	{
		result = nb * ft_recursive_factorial(nb-1);
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

	printf("%d\n", ft_recursive_factorial(nb1));
	printf("%d\n", ft_recursive_factorial(nb2));
	printf("%d\n", ft_recursive_factorial(nb3));
	printf("%d\n", ft_recursive_factorial(nb4));
	printf("%d\n", ft_recursive_factorial(nb5));

	return 0;
}

