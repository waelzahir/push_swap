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
        temp->num = i;
        i++;
    }
}