#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	return (c =='\t' || c == '\n' || c =='\v' ||
		c =='\f' || c ==	'\r' ||  c == ' ');
}

int	is_num(char c)
{
	return (c >='0' && c <='9');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str)
	{
		if (!is_space(*str))
		{
			if (*str == '-')
				sign = sign * -1;
			if(is_num(*str) )
				result = result * 10 + (*str - '0');
		}
		str++;
	}
	return (result * sign);
}

int main()
{
    printf("%d\n", ft_atoi("\t\n++-----+23452"));
    printf("%d\n", ft_atoi("\t\f\n--+--+552"));
    printf("%d\n", ft_atoi("-552"));
    printf("%d\n", ft_atoi("52"));
    return 0;
}
