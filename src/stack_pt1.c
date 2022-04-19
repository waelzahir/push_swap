/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pt1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 01:45:05 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/19 01:45:08 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"

t_node *array_to_list(char  **av)
{
    t_node *node;
    t_node *mem;
    int i;

    i = 0;
    node = malloc(sizeof(t_node));
    mem = node;
    if (!node)
        return (NULL);
    while (av[i])
    {
        node->num = ft_atoi(av[i]);
        ft_printf("%d\n", node->num);
        node->uni_next = malloc(sizeof(t_node));
        node = node->uni_next;
        i++;
    }
    return (mem);
}