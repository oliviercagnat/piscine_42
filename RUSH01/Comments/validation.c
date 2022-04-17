#include <stdio.h>

//void	print_matrix(int matrix[4][4]);

int	validate_top_to_bottom(int matrix[4][4], int colXup[4])
{
	int	column;
	int	line;
	int	view;
	int	cursor;

//	print_matrix(matrix); // not necessary

	column = 0;
	while (column < 4)
	{
		view = colXup[column];
		cursor = 0;
		line = 0;
		while (line < 4)
		{
			if (cursor < matrix[line][column])
			{
				view--;
				cursor = matrix[line][column];
			}
			line++;
		}
		column++;
		if (view != 0)
			return (0);
	}
	return (1);
}

int	validate_bottom_to_top(int matrix[4][4], int colXdown[])
{
	int	column;
	int	line;
	int	view;
	int	cursor;

	column = 3;
	while (column >= 0)
	{
		view = colXdown[column];
		cursor = 0;
		line = 3;
		while (line >= 0)
		{
			if (cursor < matrix[line][column])
			{
				view--;
				cursor = matrix[line][column];
			}
			line--;
		}
		column--;
		if (view != 0)
			return (0);
	}
	return (1);
}


int	validate_left_to_right(int matrix[4][4], int rowXleft[4])
{
	int	column;
	int	line;
	int	view;
	int	cursor;

	line = 0;
	while (line < 4)
	{
		view = rowXleft[line];
		cursor = 0;
		column = 0;
		while (column < 4)
		{
			if (cursor < matrix[line][column])
			{
				view--;
				cursor = matrix[line][column];
			}
			column++;
		}
		line++;
		if (view != 0)
			return (0);
	}
	return (1);
}

int	validate_right_to_left(int matrix[4][4], int rowXright[4])
{
	int	column;
	int	line;
	int	view;
	int	cursor;

	line = 3;
	while (line >= 0)
	{
		view = rowXright[line];
		cursor = 0;
		column = 3;
		while (column >= 0)
		{
			if (cursor < matrix[line][column])
			{
				view--;
				cursor = matrix[line][column];
			}
			column--;
		}
		line--;
		if (view != 0)
			return (0);
	}
	return (1);
}
