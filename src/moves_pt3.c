/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_pt3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:52:14 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/20 23:52:15 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"

void    rrb(t_stacks *stacks, int mode)
{
    if (stacks->b_tail &&  stacks->b_size > 0)
    stacks->b_tail = stacks->b_tail->uni_next;
    if (mode == 0)
        ft_printf("rrb\n");
}
void    rrr(t_stacks *stacks)
{
    if (stacks->a_tail && stacks->a_tail &&
    stacks->a_size > 0 && stacks->b_size > 0)
    {
        rra(stacks, 1);
        rrb(stacks, 1);
    }
    ft_printf("rrr\n");
}