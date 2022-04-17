#include <unistd.h>
#include <stdio.h>
#include "functions.h"

/*  NOT NEEDED
int	is_parameter_valid(char *param) // not really understand what it is, it works without it
{
	unsigned int	i;
	unsigned int	param_size;

	i = 0;
	param_size = ft_strlen(param);
	if (param_size != 31)
		return (1);
	while (i < param_size)
	{
		if (i % 2 == 0)
		{
			if (param[i] < '1' || param[i] > '4')
				return (1);
		}
		else if (param[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
 NOT NEEDED  */

int	is_board_valid(int board[4][4])
{
	int	i;  // rows
	int	j;  // column

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (board[i][j] + board[i + 1][j] < 3 || // the opposites have to be between (min 1 + 2) 3 and  (4+1 or 3+2) 5
				board[i][j] + board[i + 1][j] > 5)
			{
				return (0);
			}
			j++;
		}
		i += 2; // we always want to compare the opposite one, because 1st time we check all the rows, then all the columns
	}
	return (1);
}
