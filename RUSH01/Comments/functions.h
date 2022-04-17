#ifndef FUNCTIONS_H
# define FUNCTIONS_H

unsigned int	ft_strlen(char *str);
int				is_parameter_valid(char *str);
int				is_board_valid(int board[4][4]);
int				validate_top_to_bottom(int matrix[4][4], int colXup[4]);
int				validate_bottom_to_top(int matrix[4][4], int colXdown[4]);
int				validate_left_to_right(int matrix[4][4], int rowXleft[4]);
int				validate_right_to_left(int matrix[4][4], int rowXright[4]);

#endif
