#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    struct s_stack *previous;
    int num;
    struct  s_stack *next;
}   t_stack;

typedef struct s_head
{
    t_stack *a_head;
    t_stack *b_head;
} t_head;

#endif