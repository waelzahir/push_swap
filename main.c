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
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];  
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
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
        rvereseArray(array, 0, ac -2);
        univ = array_to_list(av + 1);
        st_index(univ, array, ac -1);
        push_swap(univ, ac -1 );
    }
      exit(0);
}