/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:28:28 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/18 00:28:29 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void check_dup(int *array, int len)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    while (i <= len)
    {
        ft_printf(" comp %d, %d\n", array[i], array[j]);
        if (array[i] == array[j])
        {
            ft_bzero(array, (len + 1) * 4);
            free(array);
            array = NULL;
            ft_printf("Error\n");
            return ;
        }
        j++;
        i++;
    }
}

int *get_values(char    **av, int len)
{
    int *array;
    int i;

    array = malloc(len * sizeof(int));
    if (!array)
        return (NULL);
    i = 0;
    while (av[i])
    {
        array[i] = ft_atoi(av[i]);
        i++;
    }
    quicksort(array, 0 ,  i - 1);
    check_dup(array, i -1);
    return (array);
}