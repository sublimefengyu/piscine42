int ft_is_prime(int nb)
{
	int i;

	if (nb < 2)
	  return (0);
	i = 2;
	while ( i < nb)
	{ 
		if(nb % i == 0)
			return (0);
		i++;
  	}
  	return (1);
}
#include <stdio.h>
int main ()

{
	printf("%d\n", ft_is_prime(1));
printf("%d\n", ft_is_prime(2));
printf("%d\n", ft_is_prime(3));
printf("%d\n", ft_is_prime(6));
printf("%d\n", ft_is_prime(11));
printf("%d\n", ft_is_prime(12));
printf("%d\n", ft_is_prime(-3));

return 0;
}
