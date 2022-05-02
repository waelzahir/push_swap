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
        temp->index = i;
        i++;
    }
}
t_stacks   *init_stacks(t_node *a_tail, int size)
{
    t_stacks *stacks;

    stacks = malloc(sizeof(t_stacks));
    stacks->a_tail = a_tail;
    stacks->b_tail = NULL;
    stacks->a_size = size - 1;
    stacks->b_size = -1;
    return (stacks);
}
void    link_to_big(t_node *tail, int size)
{
    t_node  *temp;
    temp = tail;
    int i = 0;
    int j = 1;
    while (i < size)
    {
        while (tail->index != i)
            tail = tail->uni_next;
         while (temp->index != j)
            {
  
            temp = temp->uni_next;
            }
        tail->bigger = temp;
        i++;
        j++;
    }
    temp->bigger = NULL;
}
void push_half(t_stacks *stacks,int len)
{
    int i = 0;
    while (i <= len)
    {
        pb(stacks);
        i++;
    }
}
void    ftprints(t_stacks *stacks)
{
    int i = 0;
    ft_printf("\n");
ft_printf("\n");


while (i != stacks->b_size + 1 )
{
    if (stacks->b_tail)
    {
        ft_printf("b %d  \n", stacks->b_tail->num);
        stacks->b_tail = stacks->b_tail->uni_next;
    }
    else 
    ft_printf(" b empty\n");
    i++;
}
i = 0;
while (i != stacks->a_size + 1)
{
    if (stacks->a_tail)
    {
        ft_printf("a %d \n", stacks->a_tail->num);

        stacks->a_tail = stacks->a_tail->uni_next;
    }
    else 
    ft_printf("a empty\n");
    i++;
}
}
int get_smal_in(t_node *tail, int size)
{
    int i;
    int index;

    t_node *temp;
    t_node *temp2;
    temp = tail;
    index = tail->index;
    i = 0;
    while (i < size)
    {
      if (index  < temp->index)
            index = temp->index;
            temp = temp->uni_previous;
        i++;
    }
       i = 0;
    temp2 =tail;

    while (i < size)
    {
        if (temp2->index == index)
            break ;
         temp2 = temp2->uni_previous;
        i++;
    }
    return i;

}
void drra(t_stacks *stacks, int times)
{
    int i;
    i = 0;
    while(i < times)
    {
        rra(stacks, 0);
        i++;
    }
}
void dra(t_stacks *stacks, int times)
{
    int i;
    i = 0;
    while(i < times)
    {
        ra(stacks, 0);
        i++;
    }
}void drrb(t_stacks *stacks, int times)
{
    int i;
    i = 0;
    while(i < times)
    {
        rrb(stacks, 0);
        i++;
    }
}void drb(t_stacks *stacks, int times)
{
    int i;
    i = 0;
    while(i < times)
    {
        rb(stacks, 0);
        i++;
    }
}
int get_index(t_node *tail, int index)
{
    t_node *temp;
    int i;

    i = 0;
    temp = tail;
    while (temp->index != index)
    {

        temp = temp->uni_next;
        i++;
    }
    return i;
}
int sorted(t_node *head, int times)
{
    int i;
    t_node *temp;

    temp = head;
    i = 0;
    while (i < times)
    {
        if (times != temp->index)
            return (0);
        temp = temp->uni_next;
        i++;
    }
    return 1;
}

void push_unsorted(t_stacks *stacks)
{
    int i;
    t_node *temp;


    i = get_index(stacks->a_tail, 0);
    if (i > (stacks->a_size /2))
        dra(stacks, stacks->a_size - i);
    else
        drra(stacks, i + 1);
    i = 0;
    temp = forward_increment(stacks->a_tail, stacks->a_size);
    while (sorted(temp, stacks->a_size) == 0 && stacks->a_tail->index != 0)
    {
            temp = forward_increment(stacks->a_tail, stacks->a_size);

        if (temp->bigger != temp->uni_next)
        {
            rra(stacks, 0);
            pb(stacks);
        }
        else 
            rra(stacks, 0);


    }    
}
void    sort_rest(t_stacks *stacks)
{
    int b;
    t_node  *head;

    while (stacks->b_size != -1)
    {
        

        head = forward_increment(stacks->a_tail,stacks->a_size);

        b = get_index(stacks->b_tail, head->index + 1);

            if (b > (stacks->b_size /2))
            drb(stacks, stacks->b_size - b );
        else
            drrb(stacks, b + 1);
        pa(stacks);


    }

}

void self_sort(t_stacks *stacks)
{
    t_node *heada;
    t_node *headb;
    int size = stacks->a_size;
    push_unsorted(stacks);

    sort_rest(stacks);

}

void    push_swap(t_node    *a_tail, int size)
{
    t_stacks *stacks;
    t_node *temp;
    temp = a_tail;

    stacks  = init_stacks(a_tail, size);
    link_to_big(temp,stacks->a_size);
     self_sort(stacks);
    



}