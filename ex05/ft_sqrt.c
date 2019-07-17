int ft_sqrt(int nb)
{
	int i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i <= nb)
	{
		if ( i * i == nb)
			return (i); 
		i++;
	}
	return (0);
}

#include <stdio.h>
int main ()
{
printf("%d \n", ft_sqrt(-1));
printf("%d \n", ft_sqrt(1));
printf("%d \n", ft_sqrt(0));
printf("%d \n", ft_sqrt(2));
printf("%d \n", ft_sqrt(4));
printf("%d \n", ft_sqrt(16));
printf("%d \n", ft_sqrt(81));


return 0;

}
