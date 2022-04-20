#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct s_node
{
    struct s_node  *uni_next;
    int num;
    struct s_node  *uni_previous;
} t_node;

int check_values(char   **av);
int *get_values(char    **av, int len);
void quicksort(int *arr, int low, int high);
int *check_dup(int *array, int len);
t_node *array_to_list(char **av);
t_node   *panic(t_node    *mem);
void    st_index(t_node *univ, int *array, int len);
#endif