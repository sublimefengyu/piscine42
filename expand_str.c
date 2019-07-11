#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space_char(char c)
{
	return c == ' ' || c == '\t';
}

void	expand_str(char *str)
{
	int	is_space_printed;
	char	*tail;

	tail = str;
	// 去掉后面的空格
	while (*tail)
		tail++;	
	tail--;
	while (is_space_char(*tail))
		tail--;

	is_space_printed = 1;
	while (*str && str <= tail)
	{
		if (is_space_char(*str))
		{
			if (!is_space_printed)
			{
				write(1, "   ", 3);
				is_space_printed = 1;
			}
		}
		else
		{
			ft_putchar(*str);
			is_space_printed = 0;
		}
		str++;
	}
	ft_putchar('\n');
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
	}
	else
	{
		if (argv[1][0] == '\0')
		{
			ft_putchar('\n');
		}
		else
		{
			expand_str(argv[1]);
		}
	}

	return (0);
}
