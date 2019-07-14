#include <stdio.h>

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == ' ' ||
		c == '\v' || c == '\f' || c == '\r');
}

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int number;
	int sign;
	
	number = 0;
	sign = 1;
	
	while (*str && is_space(*str))
		str++;

	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}

	while (*str && is_number(*str))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (sign * number);
}

int	main()
{
	printf("%d\n", ft_atoi("\t\n++-----+23452"));
	printf("%d\n", ft_atoi("\t\f\n--+--+552"));
	printf("%d\n", ft_atoi("-552"));
	printf("%d\n", ft_atoi("52"));
	return 0;
}
