int ft_is_prime(int nb)
{
	int i;

	
	i = 2;
	while ( i < nb)
	{ 
		if(nb % i == 0)
			return (0);
		i++;
  	}
  	return (1);
}

int ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (0);
	if (ft_is_prime(nb))
		return (nb);
	
	while (!ft_is_prime(nb+1))
		nb++;
	return (nb+1);

}
#include <stdio.h>
int main ()

{
printf("%d\n", ft_find_next_prime(1));
printf("%d\n", ft_find_next_prime(2));
printf("%d\n", ft_find_next_prime(3));
printf("%d\n", ft_find_next_prime(6));
printf("%d\n", ft_find_next_prime(11));
printf("%d\n", ft_find_next_prime(12));
printf("%d\n", ft_find_next_prime(-3));

return 0;
}
