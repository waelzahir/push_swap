/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:59:49 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/24 15:59:50 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	flush_bools(t_stacks *stacks)
{
	int i;
	t_stack *temp;

	i = 0;
	temp = stacks->a_tail;
	while (stacks->a_size > -1 && i < stacks->a_size)
	{
		temp->out = false;
		temp->in = false;
		temp = temp->next;
		i++;
	}
	i = 0;
	temp = stacks->b_tail;
	while (stacks->b_size > -1 && i < stacks->b_size)
	{
		temp->out = false;
		temp->in = false;
		temp = temp->next;
		i++;
	}
}
int	flag_to_out(t_stacks *stacks, int	*array,	int	total)
{
	int i;
	int piv;
	t_stack	*temp;

	if (total >= 499)
		piv = stacks->a_size / 5;
	else
		piv = stacks->a_size / 3;
	temp = stacks->a_tail;
	i = 0;
	while (i < stacks->a_size + 1)
	{
		if (temp->num <= array[piv])
			temp->out = true;
		temp = temp->next;
		i++;
	}
	return	(piv);
}
int bool_count(t_stack *stack, int times)
{
	t_stack *temp;
	int i;
	int count;

	i = 0;
	count = 0;
	temp = stack;
	while (i < times + 1)
	{
		if (temp->out == true)
			count++;
		temp = temp->next;
		i++;
	}
	return count;
}

int flaged_to_b(t_stacks *stacks, int *array, int piv)
{
	int count;
	int i;
	t_stack	*temp;
	int	rotate;

	rotate = 0;
	count = bool_count(stacks->a_tail, stacks->a_size);
	i = 0;
	while (i != count)
	{
		temp = forward_increment(stacks->a_tail, stacks->a_size);
		if (temp->out == true)
			{
				if (temp->num <= array[piv])
					{
						pb(stacks, 0);
						rb(stacks, 0);
					}
				else
					pb(stacks, 0);
				i++;
			}
			else
				ra(stacks, 0);
	}
	return	(count);
}

void	drrb(t_stacks *stacks, int times)
{
	int i;
	i = 0;
	while(i < times)
	{
		rrb(stacks, 0);
		i++;
		}
}

void	drb(t_stacks *stacks, int times)
{
	int i;
	i = 0;
	while(i < times)
	{
		rb(stacks, 0);
		i++;
		}
}

void	rotate_b(t_stacks *stacks, int index)
{
	t_stack *temp;
	int i;
	int	j;

	j = stacks->b_size / 2;
	i = 0;
	temp = stacks->b_tail;
	while (1)
	{
		if (temp->index == index)
			break;
	temp = temp->next;
		i++;
	}
	if (i == 0)
		rrb(stacks, 0);
	else if (i == stacks->b_size)
		return ;
	else if (i < j)
		drrb(stacks, i + 1);
	else
		drb(stacks, stacks->b_size - i);




}
void	reverse_push(t_stacks *stacks)
{
	t_stack	*temp;

	while (stacks->b_size != -1)
	{
		temp = forward_increment(stacks->a_tail, stacks->a_size);
		rotate_b(stacks, temp->index - 1);
		pa(stacks, 0);
	}
}
void	push_swap(t_stacks *stacks,	int	*array)
{
	int	total;
	int count;
	int piv;

	count = 0;
	total = stacks->a_size;
	flush_bools(stacks);
	while (stacks->a_size > 0)
	{
		piv = flag_to_out(stacks, array + count, total);
		count += flaged_to_b(stacks, array + count, piv / 2);
		flush_bools(stacks);
	}
	reverse_push(stacks);
}
