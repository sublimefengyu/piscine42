#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// octet 字节
// octal 八进制
// decimal 十进制
// hexadecimal 十六进制
// binary 二进制
void	print_bits2(unsigned char octet)
{
	char	binary[10];
	int	i;
	
	i = 0;
	binary[9] = '\0';
	while (octet > 0)
	{
		binary[i] = octet % 2 + '0';
		octet = octet / 2;
		i++;
	}
	while (i < 8)
	{
		ft_putchar('0');
		i++;
	}
	printf("%s", binary);
}

void	print_bits(unsigned char octet)
{
	int oct;
	int	div;
	
	div = 128;
	oct = octet;
	while (div > 0)
	{
		if (div <= oct)
		{
			ft_putchar('1');
			oct = oct % div;
		}
		else
		{
			ft_putchar('0');
		}
		div = div / 2;
	}
}

int	main()
{
	print_bits2(127);
	printf("\n");
	print_bits(127);
/*
	print_bits(2);
	print_bits(15);
	print_bits(126);
*/
	return 0;	
}
