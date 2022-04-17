#include <unistd.h>
#include <stdio.h>
#include "functions.h"

/*
** Fill the external matrix with the values sent in the parameter
** The matrix layout is as follows:
** matrix[0][X] = colXup
** matrix[1][X] = colXdown
** matrix[2][X] = rowXleft
** matrix[3][X] = rowXright
*/


void	fill_external_matrix(int matrix[4][4], char *prm)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = ft_strlen(prm);  // count size of parameters input // size is 31
	while (i < (size / 2) + 1) // we divide by 2 for excluding spaces, cause include spaces for each numbers and then +1
	{
		matrix[i / 4][i % 4] = prm[i * 2] - '0'; // /'0' convert the type char into int/
		i++;
	}
} // avoid the spacing by mltiplying by 2, the arguments always include space, only interesting into even slots.
// [i] will go up to 15


void	print_matrix(int matrix[4][4])
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp = matrix[i][j] + '0';
			write(1, &tmp, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	place_num(int number, int matrix[4][4], int line, int column)
{
	int	i; // check if number can be placed // n is the number we want to put in
	int	j; // cursor line the row number // cursor column the colomn number

	i = -1; // we put it at -1 to start since cursor = 0
	while (++i < line) // cursor = 0
		if (matrix[i][column] == number) // check if any repetitive number // only increments i, colimn remains the same
			return (0); // if equal to number, return 0, because we can't place 2 towers of same height
	j = -1;
	while (++j < column)
		if (matrix[line][j] == number)
			return (0);
	return (1); // return 1 if not placed
}

int	fill_internal_matrix(int matrix[4][4], int external_matrix[4][4])
{
	int	line;
	int	column;
	int	n;

	line = 0;
	column = 0;
	if (place_num(n, matrix, line, column)) // if can_place = 1
	{
		matrix[line][column] = n;// if valid, we insert the number
		write(1, "To be continued ...\n", 21);
	}
}

int	main(int argc, char *argv[])
{
	char	*prm;
	int		external_matrix[4][4];
	int		internal_matrix[4][4];

	prm = argv[1];
	if (argc != 2)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	fill_external_matrix(external_matrix, prm);
	if (!checker(external_matrix))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	if (fill_internal_matrix(internal_matrix, external_matrix))
		print_matrix(internal_matrix);
	else
		write(1, "Error\n", 7);
		// I added this, in the exercise it is written that we should display it
		//when we have no solution
	return (1);
}
