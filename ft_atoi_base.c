#include <stdio.h>
#include <unistd.h>

int	is_character_used(char* base, int current_idx)
{
	int	i;

	i = 0;
	while (i < current_idx && base[i])
	{
		if (base[i] == base[current_idx])
			return (1);
		i++;
	}
	return (0);
}

void	display(int nbr, char *base, int nbr_base)
{
	unsigned int	nb;
	int	to_display;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= nbr_base)
		display(nb / nbr_base, base, nbr_base);
	to_display = nb % nbr_base;
	if (to_display > 10)
		to_display = (to_display - 10) + 'A';
	else
		to_display = to_display + '0';
	write(1, &to_display, 1);
}

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == ' ' ||
		c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(char *str)
{
	int	number;
	int	sign;

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
	while (*str && (*str >= '0' && *str <= '9'))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (sign * number);
}

void	ft_atoi_base(char *str, char *base)
{
	int	len;
	char	c;

	len = 0;
	while (base[len])
	{
		c = base[len];
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
			return;
		if (is_character_used(base, len))
			return;
		len++;
	}
	if (len < 2)
		return;
	display(ft_atoi(str), base, len);
}

int	main()
{
	ft_atoi_base("\t---+++--18", "01");  // display 10010
	printf("\n");
	ft_atoi_base("\n\t\v-15", "0123456789ABCDEF");  // display F
	printf("\n");
	ft_atoi_base("18", "poneyvif"); // display 22	
	printf("\n");
	ft_atoi_base("18", "poneyvifp"); // display nothing - p is used twice
	printf("\n");
	ft_atoi_base("18", "+01"); // display nothing - can't add +, - and other characters
	printf("\n");
	ft_atoi_base("18", ""); // display nothing - empty base string
	printf("\n");
	ft_atoi_base("18", ""); // display nothing - base string's length is 1
	printf("\n");

	return 0;
}
