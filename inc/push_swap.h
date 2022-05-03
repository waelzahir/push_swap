#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct s_node
{
    struct s_node  *uni_next;
    int num;
    struct s_node *bigger;
    int index;
    struct s_node  *uni_previous;
} t_node;

typedef struct s_stacks
{
    t_node  *temp_head;
    t_node  *temp_b_head;
    int b_size;
    int a_size;
    t_node  *a_tail;
    t_node  *b_tail;
} t_stacks;

int check_values(char   **av);
int *get_values(char    **av, int len);
void quicksort(int *arr, int low, int high);
int *check_dup(int *array, int len);
t_node *array_to_list(char **av);
t_node   *panic(t_node    *mem);
int *panic_array(int    *array, int len);
void    st_index(t_node *univ, int *array, int len);
void    push_swap(t_node    *a_tail, int size);
t_node  *forward_increment(t_node   *node, int times);
void    reint(t_stacks *stacks, int state);
void swap(int* a, int* b);
void    sa(t_stacks *stacks, int sig);
void    sb(t_stacks *stacks, int sig);
void    ss(t_stacks *stacks, int sig);

void    pb(t_stacks *stacks, int sig);
void    pa(t_stacks *stacks, int sig);
t_node *init_push(t_node *node);
void    add_node(t_node *tail, int size, t_node *node);
t_node  *delete_node(t_node *tail, int size);
void    ra(t_stacks *stacks, int mode);
void    rb(t_stacks *stacks, int mode);
void    rr(t_stacks *stacks, int sig);
void    rra(t_stacks *stacks, int mode);
void    rrb(t_stacks *stacks, int mode);
void    rrr(t_stacks *stacks, int sig);
void get_seq(int *bits);
void    radix_sort(t_stacks *stacks);
 void mini_sort(t_stacks *stack);
void    ftprints(t_stacks *stacks);
t_stacks   *init_stacks(t_node *a_tail, int size);
int sorted(t_node *head, int times);
void    link_to_big(t_node *tail, int size);


#endif