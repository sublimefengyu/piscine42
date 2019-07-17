int ft_fibonacci(int index)
{
	 if(index < 0)
		 return (-1);
	 if(index <= 1)
		 return (index); 
	 else
		 return (ft_fibonacci(index-2) + ft_fibonacci(index-1));
}

#include <stdio.h>

int main ()
{
printf("%d\n", ft_fibonacci(5));
printf("%d\n", ft_fibonacci(-5));
printf("%d\n", ft_fibonacci(0));
printf("%d\n", ft_fibonacci(10));

		return 0;

}

