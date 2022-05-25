/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:54:39 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 23:21:30 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	twd_len(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		i++;
	}
	return (i);
}

void	d_free(char	**args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	args = NULL;
}

int	*arr_panic(int *array, int len, int mode)
{
	if (mode == 1)
		ft_printf("Error\n");
	ft_bzero(array, (len + 1) * 4);
	free(array);
	return (NULL);
}

t_stack	*panic(t_stack *mem, int *array)
{
	t_stack	*temp;

	temp = mem;
	while (mem)
	{
		mem = mem->next;
		free(temp);
		temp = NULL;
		temp = mem;
	}
	if (array)
		free(array);
	return (NULL);
}
