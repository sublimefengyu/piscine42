#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int main ()
{
	printf("%d \n", ft_recursive_power(3, 3));

	printf("%d \n", ft_recursive_power(0,0));

	printf("%d \n", ft_recursive_power(-1, 0));

	printf("%d \n", ft_recursive_power(-3, 3));

	return 0;

}
