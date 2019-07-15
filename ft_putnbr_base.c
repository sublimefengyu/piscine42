#include<stdio.h>
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_repeated(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *base)
{
	int	count;

	count = 0;
	while (*base)
	{
		if(!((*base >= '0' && *base <= '9') || (*base >= 'a' && *base <= 'z') ||
			(*base >= 'A' && *base <= 'Z')))
			return (0);
		if (is_repeated(base))
			return (0);
		count++;
		base++;
	}
	return (count);
}

void trans_num(unsigned int nbr, char *base, int n)
{
	if(nbr > 0)
	{
		trans_num(nbr / n, base, n);
		ft_putchar(base[nbr % n]);
	}
}

void ft_putnbr_base(int nbr, char *base)
{
	unsigned int	number;
	int	len;

	len = ft_strlen(base);
	if (len < 2)
		return;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return;
	}
	if (nbr < 0)
	{	
		number = nbr * -1;
		ft_putchar('-');
	}
	else
		number = nbr;
	trans_num(number, base, len);
}
