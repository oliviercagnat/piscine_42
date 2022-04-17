#ifndef FUNCTIONS_H
# define FUNCTIONS_H

unsigned int	ft_strlen(char *str);
int				checker(int board[4][4]);
void			fill_external_matrix(int matrix[4][4], char *param);
void			print_matrix(int matrix[4][4]);
int				place_num(int number, int matrix[4][4], int line, int column);

#endif
