/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:29:20 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/17 23:29:21 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
void print_array(int *array,int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        ft_printf("num %d\n", array[i]);
        ft_printf("index %d\n", i);
        i++;
    }
}

int main (int ac, char  **av)
{
    int *array;
    t_node  *univ;

    univ = NULL;
    if (ac >= 2)
    {
        if (check_values(av + 1) == 0)
            return (0);
        array = get_values(av + 1, ac - 1);
        if (array == NULL)
            return (0);
        univ = array_to_list(av + 1);
        st_index(univ, array, ac -1);
        print_array(array, ac-1);
    }
    int i = 0;
    while (i != ac -1 )
    {
        ft_printf("indexing %d\n", univ->num);
        univ = univ->uni_next;
        i++;
    }
}