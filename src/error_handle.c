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
