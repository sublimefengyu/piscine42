#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*g_input;
int	g_n;
int	**g_solution;
int	g_find;

int	get_col_up(int i)
{
	if (i == 0)
		return (g_input[0] - '0');
	return (g_input[i * 2] - '0');
}

int	get_col_down(int i)
{
	return (g_input[(i + g_n) * 2] - '0');
}

int	get_row_left(int i)
{
	return (g_input[(i + 2 * g_n) * 2] - '0');
}

int get_row_right(int i)
{
	return (g_input[(i + 3 * g_n) * 2] - '0');
}

int	is_valid_row_left(int *current_row, int left)
{
	int	current_left;
	int	max;
	int	i;

	current_left = 1;
	max = current_row[0];
	i = 1;
	while (i < g_n)
	{
		if (current_row[i] > max)
		{
			current_left++;
			max = current_row[i];
		}
		i++;
	}
	return (current_left == left);
}

int	is_valid_row_right(int *current_row, int right)
{
	int	current_right;
	int	max;
	int	i;

	current_right = 1;
	max = current_row[g_n - 1];
	i = g_n - 2;
	while (i >= 0)
	{
		if (current_row[i] > max)
		{
			current_right++;
			max = current_row[i];
		}
		i--;
	}
	return (current_right == right);
}

int	is_valid_row(int *current_row, int left, int right)
{
	return (is_valid_row_left(current_row, left) && is_valid_row_right(current_row, right));
}

int	is_valid_col_up(int col, int up)
{
	int	current_up;
	int	max;
	int	i;

	current_up = 1;
	max = g_solution[0][col];
	i = 1;
	while (i < g_n)
	{
		if (g_solution[i][col] > max)
		{
			current_up++;
			max = g_solution[i][col];
		}
		i++;
	}
	return (current_up == up);
}

int	is_valid_col_down(int col, int down)
{
	int	current_down;
	int	max;
	int	i;

	current_down = 1;
	max = g_solution[g_n - 1][col];
	i = g_n - 2;
	while (i >= 0)
	{
		if (g_solution[i][col] > max)
		{
			current_down++;
			max = g_solution[i][col];
		}
		i--;
	}
	return (current_down == down);
}

int	is_valid_col(int col, int up, int down)
{
	return (is_valid_col_up(col, up) && is_valid_col_down(col, down));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution()
{
	int	i;
	int	j;

	i = 0;
	while (i < g_n) 
	{
		j = 0;
		while (j < g_n) 
		{
			ft_putchar(g_solution[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	is_valid_solution()
{
	int col;

	col = 0;
	// only check col
	while (col < g_n)
	{
		if (!is_valid_col(col, get_col_up(col), get_col_down(col)))
			return 0;
		col++;
	}
	return 1;
}

int	is_number_used(int row, int col, int number)
{
	int i;
	int j;

	// check row
	i = 0;
	while (i < col)
	{
		if (g_solution[row][i] == number)
			return 1;
		i++;
	}

	// check col
	i = 0;
	while (i < row)
	{
		if (g_solution[i][col] == number)
			return 1;
		i++;
	}
	
	return 0;
}

void	find_solution(int row, int col, int left, int right)
{
	int	number;

	if (g_find)
		return;
	if (row == g_n && is_valid_solution())
	{
		print_solution();
		g_find = 1;
		return;
	}
	if (col < g_n)
	{
		number = 1;
		while (number <= g_n)
		{
			if (!is_number_used(row, col, number))
			{
				g_solution[row][col] = number;
				find_solution(row, col + 1, left, right);
				if (col == g_n - 1 && is_valid_row(g_solution[row], left, right))
					find_solution(row + 1, 0, get_row_left(row + 1), get_row_right(row + 1));
			}
			number ++;
		}
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

int	get_n()
{
	int	len;
	int	i;

	i = 3;
	len = ft_strlen(g_input);
	while (i <= 9 && i >= 3)
	{
		if (i * 8 - 1 == len)
			return i;
		i++;
	}
	return -1;
}

void	free_solution()
{
	int	i;

	i = 0;
	while (i < g_n)
	{
		free(g_solution[i]);
		i++;
	}
	free(g_solution);
}

void	init_solution()
{
	int	i;
	int	j;
	int	**solution;

	i = 0;
	g_solution = (int**) malloc(g_n * sizeof(int*));
	while (i < g_n)
	{
		g_solution[i] = (int*) malloc(g_n * sizeof(int));
		j = 0;
		while (j < g_n)
		{
			g_solution[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_error()
{
	write(1, "Error\n", 6);
}

void	rush()
{
	int	n;

	g_find = 0;
	g_n = get_n();
	if (g_n != -1)
	{
		init_solution();
		find_solution(0, 0, get_row_left(0), get_row_right(0));
		free_solution();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error();
	}
	else
	{
		g_input = argv[1];
		rush();
		if (!g_find)
		{
			print_error();
		}
	}
	return 0;
}
