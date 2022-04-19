#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

int check_values(char   **av);
int *get_values(char    **av, int len);
void quicksort(int *arr, int low, int high);

#endif