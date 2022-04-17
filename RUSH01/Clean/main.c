#include <unistd.h>
#include "functions.h"

int	main(int argc, char *argv[])
{
	char	*prm;
	int		external_matrix[4][4];
	int		internal_matrix[4][4];

	prm = argv[1];
	if (argc != 2) // if no arguments, it will be 1, then not possible, we need arguments
	{
		write(1, "Error\n", 7);
		return (1);
	}
	fill_external_matrix(external_matrix, prm); // then, we need to fill the external matrix with the arguments, to set the rules with the parameters
	if (!checker(external_matrix)) // now that we have the external matrix, we need to check if this one is correct and respect the rules of the game
	{
		write(1, "Error\n", 7);
		return (1);
	}
	if (fill_internal_matrix(internal_matrix, external_matrix))
		print_matrix(internal_matrix);
	else
		write(1, "Error\n", 7);
	return (1);
}
