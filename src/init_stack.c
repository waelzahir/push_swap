/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:38:02 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 23:18:34 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void	circular_connect(t_stack *mem, t_stack *node, int len)
{
	int	i;

	i = 0;
	node->previous = mem;
	mem = mem->previous;
	node = node->previous;
	while (len)
	{
		mem->next = node;
		mem = mem->previous;
		node = node->previous;
		len--;
	}
}

t_stack	*convert_array(char **av, int *array)
{
	t_stack	*node;
	t_stack	*mem;
	int		i;

	i = 0;
	node = malloc(sizeof(t_stack));
	mem = node;
	if (!node)
		return (panic(mem, array));
	while (av[i])
	{
		node->num = ft_atoi(av[i]);
		if (av[i + 1] == NULL)
			break ;
		node->previous = malloc(sizeof(t_stack));
		if (!node)
			return (panic(mem, array));
		node = node->previous;
		i++;
	}
	circular_connect(mem, node, i + 1);
	return (node);
}

t_stacks	*init_stacks(t_stack *stack_a, int size)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (panic(stack_a, NULL), NULL);
	stacks->a_tail = stack_a;
	stacks->b_tail = NULL;
	stacks->a_size = size - 1;
	stacks->b_size = -1;
	return (stacks);
}
