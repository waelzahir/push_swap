/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:38:55 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/19 23:38:57 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
void    reint(t_stacks *stacks,int state)
{
    stacks->temp_b_head = NULL;
    stacks->temp_head = NULL;
    if (state == 1)
    {
        stacks->a_tail->uni_next = NULL;
        stacks->a_tail->uni_previous  = NULL;
        stacks->a_tail = NULL;
    }
    else if (state == 2)
    {
        stacks->b_tail->uni_next = NULL;
        stacks->b_tail->uni_previous = NULL;
        stacks->b_tail = NULL;

    }
}

int *panic_array(int    *array, int len)
{
    ft_printf("Error\n");
    ft_bzero(array, (len + 1) * 4);
    free(array);
    return (NULL);
}

t_node   *panic(t_node    *mem)
{
    t_node  *temp;

    temp = mem;
    while (mem)
    {
        mem = mem->uni_next;
        free(temp);
        temp = NULL;
        temp = mem;
    }
    return (NULL);
}
