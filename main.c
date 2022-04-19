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
        ft_printf("%d\n", array[i]);
        i++;
    }
}

int main (int ac, char  **av)
{
    int *array;

    if (ac >= 2)
    {
        if (check_values(av + 1) == 0)
            return (0);
        array = get_values(av + 1, ac - 1);
        if (array == NULL)
            return (0);
    print_array(array, ac - 1);


    }
}