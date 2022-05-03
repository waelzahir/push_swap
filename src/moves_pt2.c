/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:52:09 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/20 23:52:10 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"


void    pa(t_stacks *stacks, int sig)
{
    t_node  *node;

    if (stacks->b_size > -1)
    {
        node = delete_node(stacks->b_tail, stacks->b_size);
        stacks->b_size--;
        if (stacks->b_size == -1)
            stacks->b_tail = NULL;
        if (stacks->a_size == -1)
            stacks->a_tail = init_push(node);
            else
            add_node(stacks->a_tail, stacks->a_size, node);
        stacks->a_size++;
        if (sig == 0)
        ft_printf("pa\n");
    }
}
void    ra(t_stacks *stacks, int mode)
{
    if (stacks->a_tail && stacks->a_size > 0)
    stacks->a_tail = stacks->a_tail->uni_previous;
    if (mode == 0)
        ft_printf("ra\n");
}
void    rb(t_stacks *stacks, int mode)
{
    if (stacks->b_tail &&  stacks->b_size > 0)
    stacks->b_tail = stacks->b_tail->uni_previous;
    if (mode == 0)
        ft_printf("rb\n");
}
void    rr(t_stacks *stacks, int sig)
{
    if (stacks->a_tail && stacks->a_tail &&
    stacks->a_size > 0 && stacks->b_size > 0)
    {
        ra(stacks, 1);
        rb(stacks, 1);
    }
    if (sig == 0)
    ft_printf("rr\n");
}
void    rra(t_stacks *stacks, int mode)
{
    if (stacks->a_tail && stacks->a_size > 0)
    stacks->a_tail = stacks->a_tail->uni_next;
    if (mode == 0)
        ft_printf("rra\n");
}
