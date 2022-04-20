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

t_node  *forward_increment(t_node   *node, int times)
{
    t_node  *temp;
    int i;

    i = 0;
    temp = node;
    while (i < times)
    {
        temp = temp->uni_next;
        i++;
    }
    return  (temp);
}
void    circular_connect(t_node *mem, t_node    *node, int len)
{
    t_node  *temp;
    int i;

    i = 0;
    node->uni_next = mem;
    mem = mem->uni_next;
    node = node->uni_next;
    while (len)
    {
        mem->uni_previous = node;
        mem = mem->uni_next;
        node = node->uni_next;
        len--;
    }

}

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
         if (av[i + 1] == NULL)
          break ;
        node->uni_next = malloc(sizeof(t_node));
        if (!node)
            return (panic(mem));
        node = node->uni_next;
        i++;
    }
    circular_connect(mem, node, i + 1);
    return (mem);
}