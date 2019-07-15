#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution(int *solution)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(solution[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

unsigned int	ft_abs(int number)
{
	if (number < 0)
		return number * -1;
	return number;
}

int	has_conflict(int *solution, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		// 在同一列
		if (solution[i] == col)
			return (1);
		// 在对角线
		if (ft_abs(col - solution[i]) == ft_abs(row -i))
			return (1);
		i++;
	}
	return (0);
}

void	find_solution(int *solution, int row, int *solution_number)
{
	int	col;

	if (row == 10)
	{
		print_solution(solution);	
		*solution_number += 1;
		return;
	}

	col = 0;
	while (col < 10)
	{
		if (!has_conflict(solution, row, col))
		{
			solution[row] = col;
			find_solution(solution, row + 1, solution_number);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	solution[10];
	int	solution_find;

	solution_find = 0;
	find_solution(solution, 0, &solution_find);
	return (solution_find);
}

int	main()
{
	ft_ten_queens_puzzle();
	return 0;
}
