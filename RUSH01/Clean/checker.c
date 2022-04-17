#include <unistd.h>
#include "functions.h"

int	checker(int rules[4][4]) // we got our matrix with the rules in argument
{
	int	i;  // rows
	int	j; // column

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4) // when j arrive
		{ // the opposites have to be between (min 1 + 2) 3 and  (4+1 or 3+2) 5
			if (rules[i][j] + rules[i + 1][j] < 3 ||
				rules[i][j] + rules[i + 1][j] > 5)
			{
				return (0); // if return 0, then the rules are not valid and we stop the game
			}
			j++;
		}
		i += 2; // we always want to compare the opposite one, because 1st time we check all the rows, then all the columns
	}
	return (1);
}
