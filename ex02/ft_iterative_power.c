
int ft_iterative_power(int nb, int power)
{
    int i;
	int result;

	i = 1;
	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else 
	{
		while( i <= power)
		{ 
			result = result * nb;
			i++;
		}
		return (result);   
	}
}

#include <stdio.h>
int main ()
{
 printf("%d \n", ft_iterative_power(3, 3));

 printf("%d \n", ft_iterative_power(0,0));

 printf("%d \n", ft_iterative_power(-1, 0));

  printf("%d \n", ft_iterative_power(-3, 2));

  return 0;

}
