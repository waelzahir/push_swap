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


void mini_ni_sort(t_stacks *stack)
{
    t_node  *tail;

    tail = stack->a_tail->uni_previous;
    if (tail->num > tail->uni_previous->num)
        sa(stack, 0);
            ftprints(stack);
    tail = stack->a_tail->uni_previous;
    if (tail->uni_next->num  < tail->uni_previous->num)
    {
        rra(stack, 0);
            ftprints(stack);

        if (tail->uni_next->num > tail->num)
            sa(stack, 0);
    }
}

