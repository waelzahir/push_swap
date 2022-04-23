/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:44:24 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/23 00:44:26 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"

void get_seq(int *bits)
{
    int i;

    i = 3; 
    bits[0] = 0;   
    bits[1] = 1;
    bits[2] = 2;
    while (i != 32)
    {
        bits[i] = bits[i - 1] * 2;

        i++; 
    }
}
void push_b(t_stacks *stacks, int mask, int is)
{
    int i;
    t_node     *head;
    i = 0;
    while (i != stacks->a_size + 1)
    {
        head = forward_increment(stacks->a_tail, stacks->a_size);
        if ((head->index & mask) == 0)
           {
                pb(stacks);
                rra(stacks, 0);
           }
        ra(stacks, 0);
        is--;
        i++;
    }
}
void    push_a(t_stacks *stacks, int is)
{
    while (stacks->b_tail->uni_next)
    {
        pa(stacks);
    }
}
int is_sorted_s(t_node *node, int size)
{
    t_node  *temp;

    int i = 0;
    int c = (size + 1) /2;

    temp = node;
    while (i != c)
    {
        if (temp->num < temp->uni_next->num) 
            return  (0);
            ft_printf("fir %d sec %d \n",temp->num,temp->uni_next->num);
        temp = forward_increment(node, 1);
        i++;
    }
    return (1);

}
void    radix_sort(t_stacks *stacks)
{
    int i;
    int bit_seq[33];
    int is;
    i = 1;


    get_seq(bit_seq);
    while (i != 32)
    {
        push_b(stacks, bit_seq[i], is);
        push_a(stacks, is);
        if (is_sorted_s(stacks->a_tail, stacks->a_size + 1) == 1)
        {
            ft_printf("yay");
            return ;
        }
        i++;
    }
}