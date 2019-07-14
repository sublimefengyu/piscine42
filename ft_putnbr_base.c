#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int	is_valid_char(char c)
{
	return ((c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= '0' && c <= '9'));
}

int	get_base(char *base)
{
	int	len;
	char c;

	if (!base[0] || !base[1])
		return (0);

	len = 0;
	while (base[len])
	{
		c = base[len];
		if (!is_valid_char(base[len]))
			return (0);
		if (is_character_used(base, len))
			return (0);
		len++;
	}
	return (len);
}

void	display(int nbr, char *base, int nbr_base)
{
	unsigned int nb;

	if (nbr < 0)
	{
		ft_putchar('-');
		nb = nbr * -1;
	}
	else
	{
		nb = nbr;
	}
	
	if (nb >= nbr_base)
	{
		display(nb / nbr_base, base, nbr_base);
	}

	ft_putchar(base[nb % nbr_base]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int nbr_base;

	nbr_base = get_base(base);		
	if (nbr_base < 2)
	{
		return;
	}
	
	display(nbr, base, nbr_base);
}

int	main()
{
	ft_putnbr_base(18, "01");  // display 10010
	ft_putchar('\n');
	ft_putnbr_base(-18, "01");  // display -10010
	ft_putchar('\n');
	ft_putnbr_base(15, "0123456789ABCDEF");  // display F
	ft_putchar('\n');
	ft_putnbr_base(-15, "0123456789ABCDEF");  // display -F
	ft_putchar('\n');
	ft_putnbr_base(18, "poneyvif"); // display 22	
	ft_putchar('\n');
	ft_putnbr_base(-18, "poneyvif"); // display -22	
	ft_putchar('\n');
	ft_putnbr_base(18, "poneyvifp"); // display nothing - p is used twice
	ft_putchar('\n');
	ft_putnbr_base(18, "+01"); // display nothing - can't add +, - and other characters
	ft_putchar('\n');
	ft_putnbr_base(18, ""); // display nothing - empty base string
	ft_putchar('\n');
	ft_putnbr_base(18, ""); // display nothing - base string's length is 1
	ft_putchar('\n');
	return 0;
}
