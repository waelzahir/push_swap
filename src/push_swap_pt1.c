/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:33:17 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/20 01:33:18 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


void    st_index(t_node *univ, int *array, int len)
{
    int i;
    t_node *temp;

    temp = univ;
    i = 0;
    while (i < len)
    {
        while (temp->num != array[i])
            temp = temp->uni_next;
        temp->index = i;
        i++;
    }
}
t_stacks   *init_stacks(t_node *a_tail, int size)
{
    t_stacks *stacks;

    stacks = malloc(sizeof(t_stacks));
    stacks->a_tail = a_tail;
    stacks->b_tail = NULL;
    stacks->a_size = size - 1;
    stacks->b_size = -1;
    return (stacks);
}

void    push_swap(t_node    *a_tail, int size)
{
    t_stacks *stacks;

    stacks  = init_stacks(a_tail, size);
    rra(stacks, 0);
      

int i = 0;
while (i != stacks->b_size + 1 )
{
    if (stacks->b_tail)
    {
        ft_printf("b %d  \n", stacks->b_tail->num);
        stacks->b_tail = stacks->b_tail->uni_next;
    }
    else 
    ft_printf(" b empty\n");
    i++;
}
ft_printf("\n");
i = 0;
while (i != stacks->a_size + 1)
{
    if (stacks->a_tail)
    {
        ft_printf("a %d \n", stacks->a_tail->num);
        stacks->a_tail = stacks->a_tail->uni_next;
    }
    else 
    ft_printf("a empty\n");
    i++;
}
}