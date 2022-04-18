/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:34:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/04/17 23:34:10 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int char_set(char c)
{
    if ( c <= '9' && c => '0' || c == '-' || c == '+')
        return (1);
    return (0);
}
int is_included(char    **av)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (char_set(av[i][j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int char_set_pos(char   *num)
{
    int i;
    int exist;

    i = 0;
    exist = 0;
    while (num[i])
    {
        if (num[i] == '+' || num[i] == '-')
            exist++;
        i++;
    }
    if (exist > 1)
        return (0);
    if (exist == 1 && (num[0] != '-' || num[0] != '+'))
        return (0);
    return (1);
}

int is_right(char   **av)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (av[i])
    {
        if (char_set_pos(av[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
int check_values(char   **av)
{
    int i;
    int j;

    i = is_included(av);
    j = is_right(av);
    if (i == 0 || j == 0)
       {
           ft_printf("Error\n");
           return (0);
       }
    return (1);
}