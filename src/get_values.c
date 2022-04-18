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

int *get_values(char    **av, int len)
{
    int *array;
    int i;

    array = ft_calloc(len * 4);
    if (!array)
        return (NULL)
    i = 0;
    while (av[i])
    {
        array[i] == ft_atoi(av[i]);
        i++;
    }
    quick_sort(array, 0 ,  i);
    return (array);
}