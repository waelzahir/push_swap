/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:09:37 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/18 02:09:38 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void swap(int* a, int* b)
{
    int t;
    
    t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(int *array, int low, int high)
{
    int *pivot;
    int i;
    int j;

    i = -1;
    j = 0;

    pivot = &array[high];
    while (i < high - 1)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
        j++;
    }
    swap(&array[i + 1], &pivot);

}
