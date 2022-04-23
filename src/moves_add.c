/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:02:04 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/23 00:02:40 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node  *delete_node(t_node *tail, int size)
{
    t_node  *node;
    t_node  *node_2;

    if (size > 0)
    {
        node = forward_increment(tail, size);
        node->uni_next = NULL;
        node->uni_previous = NULL;
        node_2 = forward_increment(tail, size - 1);
        node_2->uni_next = tail;
        tail->uni_previous = node_2;
    }
    else if (size == 0)
    {
        node = tail;
        node->uni_next = NULL;
        node->uni_previous = NULL;
    }
    return (node);

}
void    add_node(t_node *tail, int size, t_node *node)
{
    t_node  *head;

    if (size > -1)
    {
        head = forward_increment(tail, size);
        head->uni_next = node;
        tail->uni_previous = node;
        node->uni_next = tail;
        node->uni_previous = head;
    }
}

t_node *init_push(t_node *node)
{
    node->uni_next = node;
    node->uni_previous = node;
    return (node);
}
